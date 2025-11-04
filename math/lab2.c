#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double c [4][4] = {
    {0.0, 0.337, -0.076, 0.346}, 
    {-0.044, 0.0, 0.333, 0.378}, 
    {-0.21, 0.27, 0.0, -0.24}, 
    {0.207, -0.225, 0.408, 0.0}};

double b [4] = {2.385, -2.34, -0.91, 0.746};

double x [4] = {0};

int main () {
    double  mu = 0.76;
    double Bnorm = 2.385;

    int count = 0;
    double errk = pow(mu, (count + 1)) * Bnorm / (1 - mu);;
    x[0] = b[0];
    x[1] = b[1];
    x[2] = b[2];
    x[3] =b[3];

    while (errk > 0.0001) {
        x[0] = b[0] -(c[0][1] * x[1] + c[0][2]* x[2] + c[0][3] * x[3]);
        x[1] = b[1] -(c[1][0] * x[0] + c[1][2]* x[2] + c[1][3] * x[3]);
        x[2] = b[2] -(c[2][0] * x[0] + c[2][1]* x[1] + c[2][3] * x[3]);
        x[3] = b[3] -(c[3][0] * x[0] + c[3][1]* x[1] + c[3][2] * x[2]);

        count++;
        errk = pow(mu, (count + 1)) * Bnorm / (1 - mu);
        //printf("iter %d  err = %f\n", count, errk);
    };
    printf("найденное решение X = (%6.5f  %6.5f  %6.5f  %6.5f)\n Итераций: %d", x[0], x[1], x[2], x[3], count);

    return 0;
}