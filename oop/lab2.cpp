#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

int* genRandArray(int size, int max);
void print(int size, int* arr);
int** genRandMatrix(int size, int max);
void printMatrix(int size, int** matrix);

void RDiag(int* arr, int size, int** matrix)
{
    int count = 0;
    for (int d = 0; d < 2 * size - 1; d++) {
        int row, col;
        
        if (d < size) {
            row = 0;
            col = size - d - 1;
        } else {
            row = d - size + 1;
            col = 0;
        }
        
        while (row < size && col < size) {
            arr[count] = matrix[row][col];
            row++;
            col++;
            count++;
        }
    }
}

void LDiag(int* arr, int size, int** matrix)
{
    int count = 0;
    for (int d = 0; d < 2 * size - 1; d++) {
        int row, col;
        
        if (d < size) {
            row = d;
            col = 0;
        } else {
            row = size - 1;
            col = d - size + 1;
        }
        
        while (row >= 0 && col < size) {
            arr[count] = matrix[row][col];
            row--;
            col++;
            count++;
        }
    }

}

void inSpiral(int* arr, int size, int** matrix)
{
    int count = 0;
    int row = 0;
    int col = 0;
    for(int d = 0; d < ((size / 2) + (size % 2)); d++)
    {
        row = d;
        col = d;
        while(col < (size - d - 1))
        {
            arr[count] = matrix[row][col];
            col++;
            count++;
        }
        //col--;
        while(row < (size - d - 1))
        {
            arr[count] = matrix[row][col];
            row++;
            count++;
        }
        //row--;
        while(col >= d)
        {
            arr[count] = matrix[row][col];
            col--;
            count++;
        }
        col++;
        row--;
        while(row > d)
        {
            arr[count] = matrix[row][col];
            //std::cout << d << " " << row << " " << col << "\n";
            row--;
            count++;
        }
    }
}

void outSpiral(int* arr, int size, int** matrix)
{
    if (size <= 0) return;
    
    int count = 0;
    int total = size * size;
    
    // Определяем стартовую позицию (центр или левый верхний из центральных 4)
    int row = (size - 1) / 2;
    int col = (size - 1) / 2;
    
    // Для четного размера сдвигаем старт влево-вверх
    if (size % 2 == 0)
    {
        row = size / 2 - 1;
        col = size / 2 - 1;
    }
    
    arr[count++] = matrix[row][col];
    if (total == 1) return;
    
    int step = 1;
    int direction = 0; // 0=вправо, 1=вниз, 2=влево, 3=вверх
    
    while (count < total)
    {
        for (int side = 0; side < 2; side++)
        {
            for (int i = 0; i < step; i++)
            {
                // Двигаемся в текущем направлении
                switch (direction % 4)
                {
                    case 0: col++; break; // вправо
                    case 1: row++; break; // вниз
                    case 2: col--; break; // влево
                    case 3: row--; break; // вверх
                }
                
                // Добавляем элемент, если он в пределах матрицы и мы еще не все собрали
                if (row >= 0 && row < size && col >= 0 && col < size && count < total)
                {
                    arr[count++] = matrix[row][col];
                }
            }
            direction++;
        }
        step++;
        
        // Защита от бесконечного цикла
        if (step > size * 2) break;
    }
}



int main() 
{
    srand(time(NULL));
    int size = rand()%5 + 2;
    int maxValue = 100;

    int** N = genRandMatrix(size, maxValue);
    printMatrix(size, N);

    int* D = new int[size*size];

    LDiag(D, size, N);
    std::cout << "Левая диагональ ";
    print(size * size, D);
    RDiag(D, size, N);
    std::cout << "Правая диагональ ";
    print(size * size, D);

    inSpiral(D, size, N);
    std::cout << "Спираль внутрь ";
    print(size * size, D);

    int* D4 = new int[size*size];
    outSpiral(D4, size, N);
    std::cout << "Спираль наружу ";
    print(size * size, D4);

    delete[] D;
    delete N;
}

int** genRandMatrix(int size, int max)
{

    int** matrix;
    matrix = new int*[size];

    for(int i = 0; i < size; i++)
    {
        matrix[i] = genRandArray(size, max);
    }

    return matrix;
    
}

void printMatrix(int size, int**matrix)
{
    for (int i = 0; i < size; i++)
    {
        print(size, matrix[i]);
    }
}

int* genRandArray(int size, int max)
{
    int* arr;
    arr = new int[size];
    for(int i = 0; i < size; i++)
    {
        arr[i] = rand() % max;
    }


    return arr;
}

void print(int size, int* arr)
{
    for(int i = 0; i < size; i++)
    {
        printf("%4d ", arr[i]);
    }
    printf("\n");
}