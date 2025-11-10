#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <windows.h>

#define DB_SIZE 4000



typedef struct Input {
    char fio[32];
    unsigned short sum;
    char date[8];
    char attorney[22];
} Input;

typedef struct Record {
    char fio[64];
    unsigned short sum;
    char date[8];
    char attorney[44];
    int originalIndex;
} Record;

// typedef struct {
//     int originalIndex;
//     int currentIndex;
// } IndexArray;

typedef struct Queue {
    Record * data;
    struct Queue * next;
} Queue;

Record DB [DB_SIZE];
int indexes [DB_SIZE];


void readDB ();
void fillQueue (Queue **, Queue **);
void printQueue(Queue **);
void push_back(Record *, Queue **, Queue **);
Record * pop_front(Queue **, Queue **);

void printSortedDB();

char* cp866_to_utf8(const char*);

// Вариант 23
// B = 3 номер БД
// C = 2 условия упорядочения
// S = 3 метод сортировки
// D = 2 тип дерева поиска

// БД 3(обманутые вкладчики)

// Выводить на экран по 20 записей с возможностью отказа просмотра

// Упорядочить по сумме вклада и дате, вывести упорядоченную базу на экран
// Ключ = сумма вклада
// Метод сортировки: Метод пpямого слияния
// Файл базы данных загpужается в динамическую память, сортировка
// проводится с использованием очередей, для проведения поиска строится
// индексный массив.

// Быстрый поиск по ключу(сумма вклада) результаты формируются в очередь и выводятся на экран

// из записей в очереди построить дерево поиска по ключу отличному от ключа сортировки
// вывести содержимое дерева на экран(Б-дерево)
// предусмотреть возможность поиска по запросу


void readDB () {

    Input buffer;
    FILE *file;
    file = fopen("testBase3.dat", "rb");

    if (file == NULL) {
        printf("Ошибка при открытии файла!\n");
        return;
    };

    int count = 0;
    while(fread(&buffer, sizeof(Input), 1, file) == 1) {

        char * fio = cp866_to_utf8(buffer.fio);
        char * attorney = cp866_to_utf8(buffer.attorney);

        strcpy(DB[count].fio, fio);
        strcpy(DB[count].attorney, attorney);
        strcpy(DB[count].date, buffer.date);

        DB[count].sum = buffer.sum;
        DB[count].originalIndex = count;
        indexes[count] = count;
        // indexes[count].originalIndex = count;
        // indexes[count].currentIndex = count;

        count++;
        if (count >= DB_SIZE) break;
    };

    fclose(file);

    return;
}


void printPage (int pagenum) {
    printf("Старница %d\n", pagenum + 1);
    printf("| N  |             ФИО             | Cумма | Дата  |        Адвокат      |\n");
    for (int i = pagenum * 20; i < (pagenum + 1) * 20; i++) {
        printf("|%4d|%s|%7d|%s|%s|\n",(i + 1), DB[i].fio, DB[i].sum, DB[i].date, DB[i].attorney);
    }
    if((pagenum + 1) * 20 < DB_SIZE){
        printf("\nВывести еще?(y/n)\n");
    } else printf("\nЭто последняя страница\n");
    return;
}

void printDB() {
    printPage(0);
    char m[2];
    int page = 0;
    while(page < 199) {
        if (fgets(m, sizeof(m), stdin) == NULL) {
            break;
        }
        if (m[0] == 'y') {
            page++;
                system("clear || cls");
            printPage(page);
        }
        if (m[0] =='n') {
            return;
        }
    }
    if (page == 199) {
        fgets(m, sizeof(m), stdin);
    }
}


int compareDates (char x[8], char y[8]) {
    int yeardiff = (x[5] - '0') + (x[4] - '0') * 10 - (y[5] - '0') + (y[4] - '0') * 10;
    int monthdiff = (x[2] - '0') + (x[1] - '0') * 10 - (y[2] - '0') + (y[1] - '0') * 10;
    if (yeardiff < 0) {
        return 1;
    } else if (yeardiff > 0) {
        return 0;
    } else if (monthdiff <= 0) {
        return 1;
    } else return 0;
}

int less (Record * x, Record * y) {
    if (x->sum < y->sum) {
        return 1;
    } else if (x->sum > y->sum) {
        return 0;
    } else return compareDates(x->date, y->date);
}


void merge(int q, int r, Queue **a_tail, Queue **a_head, Queue **b_tail, Queue **b_head, Queue **c_tail, Queue **c_head, int indexStart)
{
    Record * record;

    while (q != 0 && r != 0)
    {
        
        if (less((*a_head)->data, (*b_head)->data))
        {
            record = pop_front(a_tail, a_head);
            push_back(record, c_tail, c_head);
            q--;
        } else
        {
            record = pop_front(b_tail, b_head);
            push_back(record, c_tail, c_head);
            r--;
        }

    };

    while(q > 0)
    {
        record = pop_front(a_tail, a_head);
        push_back(record, c_tail, c_head);

        q--;
    };

    while(r > 0)
    {
        record = pop_front(b_tail, b_head);
        push_back(record, c_tail, c_head);

        r--;
    };

    return;
};

void merge_sort(Queue **tail, Queue **head, int n)
{
    Queue *a_tail = NULL, *a_head = NULL;
    Queue *b_tail = NULL, *b_head = NULL;

    while(*head != NULL)
    {
        if(*tail != *head)
        {
            push_back(pop_front(tail, head), &a_tail, &a_head);
            push_back(pop_front(tail, head), &b_tail, &b_head);
        } else 
        {
            push_back(pop_front(tail, head), &a_tail, &a_head);
        };
    };

    int q = 1, r= 1, p = 1;
    while(p < n)
    {
        int i = 0, m = n;
        Queue *c_tail[2] = {NULL, NULL}, *c_head[2] = {NULL, NULL};
        int currentIndexPosition = 0;

        while(m > 0)
        {
            if (m > p)
            {
                q = p;
            } else q = m;
            m = m - q;
            if (m > p)
            {
                r = p;
            } else r = m;
            m = m - r;
            merge(q, r, &a_tail, &a_head, &b_tail, &b_head, &c_tail[i], &c_head[i], currentIndexPosition);
            i = 1 - i;

            currentIndexPosition += q + r;
        }
        a_head = c_head[0];
        b_head = c_head[1];
        a_tail = c_tail[0];
        b_tail = c_tail[1];
        p = p * 2;
    }; 
    *head = a_head;
    *tail = a_tail;

    return;
};

void formIndexed (Queue ** head) {
    Queue * temp = *head;
    int i = 0;
    while(temp != NULL)
    {
        indexes[i] = temp->data->originalIndex;
        temp = temp->next;
        i++;
    };
}

void sortDB () {
    Queue * tail = NULL;
    Queue * head = NULL;

    fillQueue(&tail, &head);

    merge_sort(&tail, &head, DB_SIZE);
    //printQueue(&head);
    formIndexed (&head);

    
    
}

void quickSearch (int key) {
    sortDB();

    int left = 0;
    int right = DB_SIZE;
    while (left < right) {
        int m = (left + right) / 2;
        
        if (DB[indexes[m]].sum < key) {
            left = m + 1;
        } else {
            right = m;
        }
    }
    if (DB[indexes[right]].sum == key) {
        printf("Результаты поиска:\n");
        printf("| N  |             ФИО             | Cумма | Дата  |        Адвокат      |\n");
        
        int i = right;
        while (DB[indexes[i]].sum == key){
            printf("|%4d|%s|%7d|%s|%s|\n", (i + 1), DB[indexes[i]].fio, DB[indexes[i]].sum, DB[indexes[i]].date, DB[indexes[i]].attorney);
            i++;
        }
    } else {
        printf("Нет записей с суммой %d\n", key);
    }

    printf("Для выхода в меню нажмите 0");
    char menu[2];
    while (menu[0] != '0') {
        fgets(menu, sizeof(menu), stdin);
    if(menu[0] == '0') {
        return;
    }
    }

}


int main() {
    readDB();
    char menu[2];
    do {
        printf("База данных <Обманутые вкладчики> считана\n\n");
        printf("Меню:\n");
        printf("1. Просмотр БД\n");
        printf("2. Упорядочить по сумме вклада и дате, вывести упорядоченную базу на экран\n");
        printf("3. Быстрый поиск по сумме вклада\n");
        printf("4. Построить дерево по ключу отличному от ключа соритровки\n");
        printf("0. ВЫХОД\n");

        fgets(menu, sizeof(menu), stdin);
        system("clear || cls");
        switch(menu[0])
        {
            case '1' :
                printDB();
                break;
            case '2' :
                sortDB();
                printSortedDB();
                break;
            case '3' :
                printf("Введите сумму вклада: ");
                int key;
                scanf("%d", &key);
                quickSearch(key);
                break;
            // case 4 :
            //     printDB();
            //     break;
            case '0' :
                break;
            default : 
            printf("неверный режим\n");
            break;
        }
        printf("\n");

    } while (!(menu[0] == '0'));


    return 0;
}


void push_back(Record * new, Queue **tail, Queue **head) 
{
    if((*tail) != NULL)
    {
        Queue *temp = malloc(sizeof(Queue));
        temp->data = new;
        temp->next = NULL;
        (*tail)->next = temp;
        *tail = temp;
    } else 
    {
        *tail = malloc(sizeof(Queue));
        (*tail)->data = new;
        (*tail)->next = NULL;
        *head = *tail;
    };

    return;
};

Record * pop_front(Queue **tail, Queue **head)
{
    if (*head != NULL)
    {
        Queue *temp = *head;
        Record * data = (*head)->data;
        *head = (*head)->next;
        free(temp);
        if(*head == NULL)
        {
            *tail = NULL;
        }
        return data;
    }
    return NULL;
};

void fillQueue (Queue ** tail, Queue ** head) {
    for (int i = 0; i < DB_SIZE; i++) 
            {
                push_back(&DB[i], tail, head);
            };
};

void printQueue(Queue **head)
{
    Queue * temp = *head;
    
    printf("| N  |             ФИО             | Cумма | Дата  |        Адвокат      |\n");
    int i = 1;
    while(temp != NULL)
    {

        printf("|%4d|%s|%7d|%s|%s|\n",temp->data->originalIndex, temp->data->fio, temp->data->sum, temp->data->date, temp->data->attorney);
        temp = temp->next;
        i++;
        if ((i % 20) == 0) {
            char m[2];
            if (fgets(m, sizeof(m), stdin) == NULL) {
            break;
        }
        if (m[0] == 'y') {
            continue;
        }
        if (m[0] =='n') {
            return;
        }
        }
    };
    printf("\n");

    return;
};

void printPageIndexed (int pagenum) {
    printf("Проиндексированный массив\n");
    printf("Старница %d\n", pagenum + 1);
    printf("| N  |             ФИО             | Cумма | Дата  |        Адвокат      |\n");
    for (int i = pagenum * 20; i < (pagenum + 1) * 20; i++) {
        printf("|%4d|%s|%7d|%s|%s|\n", (i + 1), DB[indexes[i]].fio, DB[indexes[i]].sum, DB[indexes[i]].date, DB[indexes[i]].attorney);
    }
    if((pagenum + 1) * 20 < DB_SIZE){
        printf("\nВывести еще?(y/n)\n");
    } else printf("\nЭто последняя страница\n");
    return;
}

void printSortedDB() {

    printPageIndexed(0);
    char m[2];
    int page = 0;
    while(page < 199) {
        if (fgets(m, sizeof(m), stdin) == NULL) {
            break;
        }
        if (m[0] == 'y') {
            page++;
                system("clear || cls");
            printPageIndexed(page);
        }
        if (m[0] =='n') {
            return;
        }
    }
    if (page == 199) {
        fgets(m, sizeof(m), stdin);
    }
}

static const unsigned short cp866_to_unicode[128] = {
    0x0410, 0x0411, 0x0412, 0x0413, 0x0414, 0x0415, 0x0416, 0x0417, // 0x80-0x87
    0x0418, 0x0419, 0x041A, 0x041B, 0x041C, 0x041D, 0x041E, 0x041F, // 0x88-0x8F
    0x0420, 0x0421, 0x0422, 0x0423, 0x0424, 0x0425, 0x0426, 0x0427, // 0x90-0x97
    0x0428, 0x0429, 0x042A, 0x042B, 0x042C, 0x042D, 0x042E, 0x042F, // 0x98-0x9F
    0x0430, 0x0431, 0x0432, 0x0433, 0x0434, 0x0435, 0x0436, 0x0437, // 0xA0-0xA7
    0x0438, 0x0439, 0x043A, 0x043B, 0x043C, 0x043D, 0x043E, 0x043F, // 0xA8-0xAF
    0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x2561, 0x2562, 0x2556, // 0xB0-0xB7
    0x2555, 0x2563, 0x2551, 0x2557, 0x255D, 0x255C, 0x255B, 0x2510, // 0xB8-0xBF
    0x2514, 0x2534, 0x252C, 0x251C, 0x2500, 0x253C, 0x255E, 0x255F, // 0xC0-0xC7
    0x255A, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256C, 0x2567, // 0xC8-0xCF
    0x2568, 0x2564, 0x2565, 0x2559, 0x2558, 0x2552, 0x2553, 0x256B, // 0xD0-0xD7
    0x256A, 0x2518, 0x250C, 0x2588, 0x2584, 0x258C, 0x2590, 0x2580, // 0xD8-0xDF
    0x0440, 0x0441, 0x0442, 0x0443, 0x0444, 0x0445, 0x0446, 0x0447, // 0xE0-0xE7
    0x0448, 0x0449, 0x044A, 0x044B, 0x044C, 0x044D, 0x044E, 0x044F, // 0xE8-0xEF
    0x0401, 0x0451, 0x0404, 0x0454, 0x0407, 0x0457, 0x040E, 0x045E, // 0xF0-0xF7
    0x00B0, 0x2219, 0x00B7, 0x221A, 0x2116, 0x00A4, 0x25A0, 0x00A0  // 0xF8-0xFF
};

static int unicode_to_utf8(unsigned int codepoint, char* utf8) {
    if (codepoint <= 0x7F) {

        utf8[0] = (char)codepoint;
        return 1;
    } else if (codepoint <= 0x7FF) {

        utf8[0] = (char)(0xC0 | (codepoint >> 6));
        utf8[1] = (char)(0x80 | (codepoint & 0x3F));
        return 2;
    } else if (codepoint <= 0xFFFF) {

        utf8[0] = (char)(0xE0 | (codepoint >> 12));
        utf8[1] = (char)(0x80 | ((codepoint >> 6) & 0x3F));
        utf8[2] = (char)(0x80 | (codepoint & 0x3F));
        return 3;
    } else if (codepoint <= 0x10FFFF) {

        utf8[0] = (char)(0xF0 | (codepoint >> 18));
        utf8[1] = (char)(0x80 | ((codepoint >> 12) & 0x3F));
        utf8[2] = (char)(0x80 | ((codepoint >> 6) & 0x3F));
        utf8[3] = (char)(0x80 | (codepoint & 0x3F));
        return 4;
    }
    return 0; 
}

char* cp866_to_utf8(const char* cp866_str) {
    if (cp866_str == NULL) {
        return NULL;
    }
    
    // Вычисляем максимально возможную длину UTF-8 строки (в худшем случае - 4 байта на символ)
    size_t src_len = strlen(cp866_str);
    size_t max_utf8_len = src_len * 4 + 1;
    
    // Выделяем память для результата
    char* utf8_str = (char*)malloc(max_utf8_len);
    if (utf8_str == NULL) {
        return NULL;
    }
    
    char* dest = utf8_str;
    const unsigned char* src = (const unsigned char*)cp866_str;
    
    while (*src) {
        unsigned char c = *src;
        
        if (c < 0x80) {
            *dest++ = (char)c;
        } else {
            // Символы CP866 (0x80-0xFF) преобразуем через Unicode
            unsigned int unicode_char = cp866_to_unicode[c - 0x80];
            int utf8_len = unicode_to_utf8(unicode_char, dest);
            dest += utf8_len;
        }
        
        src++;
    }
    
    *dest = '\0';
    
    return utf8_str;
}
