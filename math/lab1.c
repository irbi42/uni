#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define C 10
#define H 0.006

double rounded [16] = {0};
double approx [15], accurate [15];
double j [17];


double func (double x) {
    return pow(10, 3) * cos((x + 10 * C) / C);
}

int findLower(double x) {
    int i = 0;
    int xi = C;
    while (x < xi) {
        xi+= H;
        i++;
    }
    return i;
}

int findHigher(double x) {
    return (findLower(x) + 1);
}

double findQ (double x) {
    double xi = j[findLower(x)];
    return (x - xi) / H;
}

int main() {
    printf("----------------------\n");
    printf("Значения функции с шагом h = %f на интервале [%d, %.4f]\n", H, C, C + 15 * H);
    printf("----------------------\n");

    j[0] = C;
    for (int i = 0; i < 16; i++) {
        rounded[i] = round(func(j[i]) * 10000) / 10000.0;
        printf("| %7.4f | %8.4f | \n", j[i], rounded[i]);
        j[i + 1] = j[i] + H;
    }
    printf("----------------------\n");
    printf("Приближенные значения функции, выч. с помощью линейной интерполяцией\n");
    printf("----------------------\n");
    printf("| Значение Xi | F(x) приближенные | F(x) точные |\n");

    
    double x = C + 0.6 * H;
    double q = findQ(x);
    for (int i = 1; i < 15; i++) {
        accurate[i] = round(func(x) * 10000) / 10000.0;
        approx[i] = rounded[findLower(x)] + q * (rounded[findHigher(x)] - rounded[findLower(x)]);
        printf("| %11.4f | %17.4f | %11.4f |\n", x, approx[i], accurate[i]);
        x = C + 0.6 * H * (i + 1);
        q = findQ(x);
    }


    return 0;
}