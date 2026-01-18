#include <stdio.h>
#include <stdlib.h>


//VARIANT 9
double variant[5][6] = {
    {8, 2, -8, -10, -3, 142,}, 
    {6, -1, 11, 4, 11, -55},
    {13, -9, -4, 3, 10, -49},
    {-9, 4, 14, 15, 13, -213},
    {9, 6, 8, 4, -7, 152}
    };

    double test[5][6] = {
    {1, -7, 4, -3, -3, -12}, 
    {-1, -5, 7, -1, 4, 30},
    {-6, 7, 7, 5, 7, 49},
    {-5, -3, -6, -3, 8, -7},
    {-5, -5, -2, -3, -6, -67}
    };

double test1 [4][5] = {
    {4, -17, -6, -5, -17},
    {43, 24, -1, 3, 28},
    {0, 1, 2, 1, 9},
    {2, 1, 0, 0, 1}
};

double test2 [3][5] = {
    {3, 2, 5, 4, 3},
    {1, -1, -1, -4, -2},
    {4, 1, 4, 0, 2}
};

double test3 [3][5] = {
    {2, -3, 5, 7, 1},
    {4, -6, 2, 3, 2},
    {2, -3, -11, -15, 1}
};


void print_matrix (double *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%8.2f ", matrix[cols * i + j]);
            if (j == (cols - 2)) {
                printf(" | ");
            }
        }
        printf("\n");
    }
    return;
}

int jordan_gaus (double *matrix, int rows, int cols) {
    for (int iter = 0; iter < rows; iter++) {
        int col = 0;
        if (matrix[iter * cols + col] == 0) {
            col++;
            while(matrix[iter * cols + col] == 0 && col < cols) {
                col++;
                
            }
            if (col == cols - 1) {
                return 1;
            }
        }
        
        if (col == cols) {
            
            continue;
        }
        double res = matrix[iter * cols + col];
        for (int i = col; i < cols; i++) {
            matrix[iter * cols + i] = matrix[iter * cols + i] / res;
        }



        for (int i = 0; i < rows; i++) {
            if (i == iter) {
                continue;
            }
            for (int j = col + 1; j < cols; j++) {
                matrix[i * cols + j] = matrix[i * cols + j] - ((matrix[iter * cols + j] * matrix[i * cols + col]) / matrix[iter * cols + col]);
            }
            
        }

        for (int i = 0; i < rows; i++){
            matrix[i * cols + col]  =  0.0;
        }
        matrix[iter * cols + col] = 1;

        printf("\n Итерация %d:\n", iter + 1);
        print_matrix((double *)matrix, rows, cols);
    }

    return 0;
}

void compile_answer (double *matrix, int rows, int cols) {
   // double *x = malloc((cols - 1) * sizeof(double));

        for (int i = 0; i < rows; i++) {
            int is_zero_line = 1;
            int basis_index = 0;
            for (int j = 0; j < cols; j++) {
                if (matrix[i * cols + j] != 0) {
                    is_zero_line = 0;
                    basis_index = j;
                    break;
                }
            }
            if(is_zero_line) {
                continue;
            } else {
                printf("x[%d] = %.2f ", basis_index + 1, matrix[i * cols + (cols - 1)]);
                for (int j = basis_index + 1; j < cols - 1; j++) {
                    if (matrix[i * cols + j] != 0) {
                        printf("+ %.2f * x[%d]", matrix[i * cols + j], j + 1);
                    }
                }
                printf("\n");
            }
        }

}

int main() {
    int option = 0;
    int rows = 0;
    int cols = 0;
    int res = 0;
    printf("Выберите матрицу для расчетов: \n");
    printf("1) Вариант 9\n");
    printf("2) Пример из задания\n");
    printf("3) Test 1\n");
    printf("4) Test 2\n");
    printf("5) Test 3\n");
    scanf("%d", &option);
    double *matrix = NULL;
    switch(option) {
        case 1:
            printf("Исходная матрица Вариант 9: \n\n");
            rows = 5;
            cols = 6;
            matrix = (double *)variant;
            break;
        case 2:
            printf("Пример из задания:  \n\n");
            rows = 5;
            cols = 6;
            matrix = (double *)test;
            break;
        case 3:
            printf("Test 1:\n\n");
            rows = 4;
            cols = 5;
            matrix = (double *)test1;
            break;
        case 4:
            printf("Test 2:\n\n");
            rows = 3;
            cols = 5;
            matrix = (double *)test2;
            break;
        case 5:
            printf("Test 3:\n\n");
            rows = 3;
            cols = 5;
            break;
        default: printf("Error");
            return 0;
            break;

    }

    print_matrix(matrix, rows, cols);
    res = jordan_gaus(matrix, rows, cols);

    switch(res) {
        case 0:
            printf("Найдено решение: \n");
            compile_answer(matrix, rows, cols);
            break;
        case 1:
            printf("Решений нет.\n");
            break;
    }


    return 0;
}