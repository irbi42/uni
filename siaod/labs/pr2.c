#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pr1.h"
#include "pr2.h"
#include "rjin.h"

int isSearchTree (struct NODE *);
struct NODE * TreeSearch (struct NODE *, int);
struct NODE * createISDP (int *, int , int );
void addToSDP (int, struct NODE **);


void run_pr2 () {
    const int n1 = 10;
    int n2 = 50, n3 = 100, n4 = 200;
    createTable2(n1);
    createTable2(n2);
    createTable2(n3);
    createTable2(n4);
    // Построить СДП и ИСДП 
    // Вычислить среднюю высоту построенных деревьев для 10 50 100 200 вершин
    // Написать проверку на дерево поиска
    // Написать процедуру поиска в дереве элемента по ключу
    // Посчитать количество операций необходимых для поиска и сравнить с высотой дерева
    return;
}

void createTable2 (int n) {
    int sorty[n]; 
    int sorty2[n], unsorty[n];

    fill_mass(unsorty, n, 4);

    for (int i = 0; i < n; i++) {
        sorty[i] = unsorty[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (sorty[i] < sorty[j]) {
                int temp = sorty[j];
                sorty[j] = sorty[i];
                sorty[i] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        sorty2[i] = sorty[n - i - 1];
    }

    // printf("%d Массивы данных: \n", n);
    // print_mass(sorty, n);
    // print_mass(sorty2, n);
    // print_mass(unsorty, n);
    
    printf("Размер | Высота ИСПД/СПД | Ср.Высота ИСПД/СПД  | Проверка | Ключ | Найден ИСПД/СПД \n");
    printf("%7d|", n);

// сортированный массив
    struct NODE *isdp = createISDP(sorty, 0, n - 1);
    struct NODE *sdp = NULL;
    for (int i = 0; i < n; i++) {
        addToSDP(sorty[i], &sdp);
    };
    int heightISDP = countHeight(isdp);
    int heightSDP = countHeight(sdp);
    printf("%8d/%7d ", heightISDP, heightSDP);

    printf("|");

    double avrISDP = countAverageHeight(isdp); 
    double avrSDP = countAverageHeight(sdp);
    printf("%10.2f/%9.2f ", avrISDP, avrSDP);

    printf("|");

    int testISDP = isSearchTree(isdp);
    int testSDP = isSearchTree(sdp);
    printf("%4d/%4d ", testISDP, testSDP);

    printf("|");

    int key = sorty[1006 % n];
    printf("%5d ", key);
    printf("|");
    struct NODE *res = TreeSearch(isdp, key);
    printf(" %4d/", (res == NULL) ? 0 : 1);
    res = TreeSearch(sdp, key); // здесь будет поиск по СДП
    printf(" %4d \n", (res == NULL) ? 0 : 1);

// обратно ссортированный массив
    printf("%7c|", ' ');
    sdp = NULL;
    for (int i = 0; i < n; i++) {
        addToSDP(sorty2[i], &sdp);
    };

    //heightISDP = 0;
    heightSDP = countHeight(sdp);
    printf("%8d/%7d ", heightISDP, heightSDP);

    printf("|");

    //avrISDP = 0; 
    avrSDP = countAverageHeight(sdp);
    printf("%10.2f/%9.2f ", avrISDP, avrSDP);

    printf("|");

    //testISDP = 0;
    testSDP = isSearchTree(sdp);
    printf("%4d/%4d ", testISDP, testSDP);

    printf("|");

    printf("%5d ", key);
    printf("|");
    free(res);
    res = NULL;
    res = TreeSearch(isdp, key);
    printf(" %4d/", (res == NULL) ? 0 : 1);
    res = TreeSearch(sdp, key); 
    printf(" %4d \n", (res == NULL) ? 0 : 1);

// случайный набор чисел
    printf("%7c|", ' ');
    sdp = NULL;
    for (int i = 0; i < n; i++) {
        addToSDP(unsorty[i], &sdp);
    };

    //heightISDP = 0;
    heightSDP = countHeight(sdp);
    printf("%8d/%7d ", heightISDP, heightSDP);

    printf("|");

    //avrISDP = 0; 
    avrSDP = countAverageHeight(sdp);
    printf("%10.2f/%9.2f ", avrISDP, avrSDP);

    printf("|");

    //testISDP = 0;
    testSDP = isSearchTree(sdp);
    printf("%4d/%4d ", testISDP, testSDP);

    printf("|");

    printf("%5d ", key);
    printf("|");
    free(res);
    res = NULL;
    res = TreeSearch(isdp, key);
    printf(" %4d/", (res == NULL) ? 0 : 1);
    res = TreeSearch(sdp, key); 
    printf(" %4d \n", (res == NULL) ? 0 : 1);


    return;
}

void addToSDP (int d, struct NODE **root) {
    if (*root == NULL) {
        *root = malloc(sizeof(struct NODE));
        (*root)->data = d;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    if (d < (*root)->data) {
        addToSDP(d, &(*root)->left);
    }
    else if (d > (*root)->data) {
        addToSDP(d, &(*root)->right);
    }
    return;
}

 struct NODE * createISDP (int *mass, int l, int r) {
    if (l > r) return NULL;
    else {
        int m = (l + r) / 2;
        struct NODE *p = malloc(sizeof(struct NODE));
        p->left = NULL;
        p->right = NULL;
        p->data = mass[m];
        p->left = createISDP(mass, l, (m - 1));
        p->right = createISDP(mass, (m + 1), r);
        return p;
    }
}

int isSearchTree (struct NODE *root) {
    if ((root != NULL)) {
        int left = isSearchTree(root->left);
        int right = isSearchTree(root->right);
        if (root->left != NULL) {
            if((root->data <= root->left->data) || !left) {
                return 0;
            }
        };
        if (root->right != NULL) {
            if((root->data >= root->right->data) || !right) {
                return 0;
            }
        };
    }
    return 1;
   // return ((root != NULL) & (((root->left != NULL) & ((root->data < root->left->data) || !(isSearchTree(root->left)))) || ((root->right != NULL) & ((root->data >= root->right->data) || !(isSearchTree(root->right)))))) ? 0 : 1;
}

struct NODE * TreeSearch (struct NODE *root, int x) {
    struct NODE *p = root;
    int count = 0;
    while (p != NULL) {
        count++;
        if (p->data < x) {
            p = p->right;
        } else if (p->data > x) {
            p = p->left;
        } else break;
    }
    printf("%3d", count);
    return p;
}