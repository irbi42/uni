#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define C 10.0
#define H 0.014

double rounded [19] = {0};
double approx [15], accurate [15];
double j [19];

double func (double x) {
    return (1/C) * sin(C * x);
}

int findLower(double x) {
    int i = 0;
    for (i = 0; i < 19; i++) {
        if (j[i] >= x) break;
    }
    i--;
    //printf("%d ", i);
    return i;
}

int findHigher(double x) {
    return (findLower(x) + 2);
}

int main () {
    printf("----------------------\n");
    printf("Значения функции с шагом h = %f на интервале [%f, %.4f]\n", H, C - H, C + 15 * H);
    printf("----------------------\n");
    printf("| Знач x  |   F(x)   |\n");
    j[0] = C - H;
    for (int i = 0; i < 19; i++) {
        rounded[i] = round(func(j[i]) * 10000) / 10000.0;
        printf("| %7.4f | %8.4f | \n", j[i], rounded[i]);
        j[i + 1] = j[i] + H;
    }
    printf("----------------------\n");
    printf("Приближенные значения производной,\n вычисленнные по формуле центральной разности\n");
    printf("----------------------\n");
    printf("| Значение Xi | F'(x) приближенные| F'(x) точные|\n");

    
    double x = C;
    
    for (int i = 0; i < 16; i++) {
        x = C + H * i;
        accurate[i] = cos(x * C);
        approx[i] = (rounded[i + 2] - rounded[i]) / (2.0 * H);
        printf("| %11.4f | %17.5f | %11.5f |\n", x, approx[i], accurate[i]);
    }

    return 0;
}