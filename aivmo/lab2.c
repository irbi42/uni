#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main () {
    int *a;
    int *b;
    int **c;
    int **x;
    int rows, cols;
    printf("Найти начальный опорный план транспортной задачи методом северо-западного угла.\n\n");

    FILE *file = NULL;
    file = fopen("data.txt", "r");
    fscanf(file, "%d %d", &rows, &cols);

    //processing A, B
    a = malloc(rows * sizeof(int));
    b = malloc(cols * sizeof(int));

    int sumA = 0;
    int sumB = 0;
    for(int i = 0; i < rows; i++) {
        fscanf(file, "%d", &a[i]);
        sumA += a[i];
    }
    for(int i = 0; i < rows; i++) {
        fscanf(file, "%d", &b[i]);
        sumB += b[i];
    }

    c = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        c[i] = (int *)malloc(cols * sizeof(int));
    }
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++) {
            fscanf(file, "%d", &c[i][j]);
        }
    }

    printf("Потребители: %d \nПоставщики: %d\n\n", sumA, sumB);

    if (sumA != sumB) {
        if (sumA > sumB) {
            cols++;
            b = realloc(b, cols * sizeof(int));
            if ((b == NULL)) {
                printf("memory allocation error\n");
                return 0;
            }
            b[cols - 1] = sumA - sumB;
        } else {
            rows++;
            a = realloc(a, rows * sizeof(int));
            if ((a == NULL)) {
                printf("memory allocation error\n");
                return 0;
            }
            a[rows - 1] = sumB - sumA;
        }
        c = (int **)realloc(c, rows * sizeof(int *));
        if ((c == NULL)) {
                printf("memory allocation error\n");
                return 0;
            }
        for (int i = 0; i < rows; i++) {
            c[i] = (int *)realloc(c[i], cols * sizeof(int));
            if ((c[i] == NULL)) {
                printf("memory allocation error\n");
                return 0;
            }
        }
    }


    x = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        x[i] = (int *)malloc(cols * sizeof(int));
    }

    fclose(file);
    printf("Исходные данные, приведенные к закрытой модели: \n");
    //printf("a %d b %d\nA: ", rows, cols);
    printf("A: ");
    for(int i = 0; i < rows; i++) {
        printf("%d ", a[i]);
    }
    printf("\nB: ");
    for(int i = 0; i < cols; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
    printf("C:\n   ");
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n   ");
    }

    printf("\n-------------\n");

    int iter = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (b[j] == 0) continue;
            if (a[i] == 0) break;
            if (a[i] >= b[j]) {
                x[i][j] = b[j];
                a[i] -= b[j];
                b[j] = 0;
            } else {
                x[i][j] = a[i];
                b[j] -= a[i];
                a[i] = 0;
            }
            iter++;
            printf("Шаг %d: \n", iter);
            for (int i = 0; i < rows; i++){
                for (int j = 0; j < cols; j++) {
                    printf("%d ", x[i][j]);
                }
                printf("\n");
            }
            printf("-------------\n");
        }
    }


    printf("\nОпорный план транспортной задачи:\n\n");
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++) {
            printf("%d ", x[i][j]);
        }
        printf("\n");
        
    }
    printf("-------------\n");

    int z = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            z += c[i][j] * x[i][j];
        }
    }

    printf("Затраты на перевозки в получившемся решении: %d\n", z);


    return 0;
}