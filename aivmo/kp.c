#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ROWS 4
#define COLS 6

double main_table [ROWS][COLS] = {
    {2, 5, -1, 0, 0, 16},
    {4, 1, 0, -1, 0, 9},
    {3, 2, 0, 0, -1, 13},
    {-6, -1, 0, 0, 0, 0}
};

// double main_table [ROWS][COLS] = {
//     {2, 3, 1, 0, 0, 6},
//     {1, 0, 0, 1, 0, 1},
//     {-1, 1, 0, 0, 1, 1},
//     {-1, -2, 0, 0, 0, 0}
// };
//int basis_indexes[3] = {2, 3, 4};


int basis_indexes[3] = {0, 1, 3};

void jordan_gaus () {
    for (int iter = 0; iter < ROWS; iter++) {
        if(iter == 3) break;
        double res = main_table[iter][basis_indexes[iter]];
        for (int i = 0; i < COLS; i++) {
            main_table[iter][i] = main_table[iter][i] / res;
        }



        for (int i = 0; i < ROWS; i++) {
            if (i == iter) {
                continue;
            }
            for (int j = 0; j < COLS; j++) {
                if (j == basis_indexes[iter]) continue;

                main_table[i][j] = main_table[i][j] - ((main_table[iter][j] * main_table[i][basis_indexes[iter]]) / 1.0);
            }
        }

        for (int i = 0; i < ROWS; i++){
            if (i == iter) continue;
            main_table[i][basis_indexes[iter]] =  0.0;
        }

        printf("\n Итерация %d:\n", iter + 1);

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%8.2f ", main_table[i][j]);
                if (j == (COLS - 2)) {
                    printf(" | ");
                }
            }
            printf("\n");
        }
    }

    return;
}

int has_negative () {
    for (int i = 0; i < COLS - 1; i++) {
        if (main_table[ROWS - 1][i] < 0) return 1;
    }
    return 0;
}

int main() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%8.2f ", main_table[i][j]);
            if (j == (COLS - 2)) {
                printf(" | ");
            }
        }
        printf("\n");
    }

    jordan_gaus();

    double min = 0;
    int min_i = 0;
    // for (int i = 0; i < COLS - 1; i++) {
    //     if (main_table[ROWS - 1][i] < 0 && main_table[ROWS - 1][i] < min) {
    //         min = main_table[ROWS - 1][i];
    //         min_i = i;
    //     }
    // }
    int count = 0;
    while (has_negative()) {
        count++;
        min = 0;
        min_i = 0;
        for (int i = 0; i < COLS - 1; i++) {
            //printf("%f\n", main_table[ROWS - 1][i]);
            if (main_table[ROWS - 1][i] < 0 && main_table[ROWS - 1][i] < min) {
                min = main_table[ROWS - 1][i];
                min_i = i;
            }
        }
        //printf("calculating SO\n");
        double so[3] = {0, 0, 0};
        for (int i = 0; i < 3; i++) {
            if (main_table[i][min_i] > 0) {
                so[i] = main_table[i][COLS - 1] / main_table[i][min_i];
            }
        }

        double so_min = INFINITY;
        int so_min_index = -1;

        for (int i = 0; i < 3; i++) {
            //printf("%d  %d\n", i, so_min_index);
            if ((so[i] < so_min || so_min == 0) && so[i] != 0) {
                so_min = so[i];
                so_min_index = i;
            }
        }

        if (so_min_index < 0) {
            printf("В разрешающем столбце нет положительных элементов! Функция не ограничена сверху!\n");
            break;
        }

        int old_basis_index = basis_indexes [so_min_index];
        basis_indexes [so_min_index] = min_i;



        double res = main_table[so_min_index][basis_indexes[so_min_index]];
        for (int i = 0; i < COLS; i++) {
            main_table[so_min_index][i] = main_table[so_min_index][i] / res;
        }

        printf("replacing %d", old_basis_index);
        for (int i = 0; i < ROWS; i++) {
            if (i == so_min_index) continue;
            main_table[i][old_basis_index] = -1 * main_table[i][min_i] / res;
        }

        for (int i = 0; i < ROWS; i++) {
            if (i == so_min_index) {
                continue;
            }
            for (int j = 0; j < COLS; j++) {
                if (j == basis_indexes[so_min_index] || j == old_basis_index) continue;

                main_table[i][j] = main_table[i][j] - ((main_table[so_min_index][j] * main_table[i][basis_indexes[so_min_index]]) / 1.0);
            }
        }

        for (int i = 0; i < ROWS; i++){
            if (i == so_min_index) continue;
            main_table[i][basis_indexes[so_min_index]] =  0.0;
        }

        printf("\n%d Симплекс Итерация %d:\n", count, min_i);

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%8.2f ", main_table[i][j]);
                if (j == (COLS - 2)) {
                    printf(" | ");
                }
            }
            if (i < 3) printf("  |   %f", so[i]);
            printf("\n");
        }

        if (count > 4) return 0;
    }

    return 0;
}