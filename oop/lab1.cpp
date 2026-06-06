#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* genRandArray(int size, int max);
void print(int* arr);
int** genRandMatrix(int size, int max);
void printMatrix(int size, int** matrix);

int main() 
{
    srand(time(NULL));
    int size = rand()%10 + 1;
    int maxValue = 100;
    int* arr = genRandArray(size, maxValue);
    print(arr);

    int** matrix = genRandMatrix(size, maxValue);
    printMatrix(size, matrix);

    delete arr;
    delete matrix;
}

int** genRandMatrix(int size, int max)
{

    int** matrix;
    matrix = new int*[size + 1];

    for(int i = 0; i < size; i++)
    {
        int s = rand() % size + 3;
        matrix[i] = genRandArray(s, max);
    }

    return matrix;
    
}

void printMatrix(int size, int**matrix)
{
    printf("\n%d\n", size);

    for (int i = 0; i < size; i++)
    {
        print(matrix[i]);
    }
}

int* genRandArray(int size, int max)
{
    //srand(time(NULL));
    int* arr;
    arr = new int[size + 1];
    arr[0] = size;
    for(int i = 1; i < size + 1; i++)
    {
        arr[i] = rand() % max;
    }


    return arr;
}

void print(int* arr)
{
    int size = arr[0];
    printf("%d:", size);
    for(int i = 1; i < size + 1; i++)
    {
        printf("%4d ", arr[i]);
    }
    printf("\n");
}