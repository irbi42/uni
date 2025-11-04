#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int iteration;

double xr [21] = {0};
double yr [21] = {0};
double h;

double xi [21] = {0};
double yi [21] = {0};


double func (double x) {
    return 3* pow(x, 4) + 4 * pow(x, 3) - 12 * pow(x, 2) - 40;
}

double chordMethod(double a, double b, double epsilon) {
    double fa = func(a);
    double fb = func(b);
    double x, fx;
    iteration = 0;

    do {
        x = a - fa * (b - a) / (fb - fa);
        fx = func(x);
        
        if (fa * fx < 0) {
            b = x;
            fb = fx;
        } else {
            a = x;
            fa = fx;
        }
        
        iteration++;
        
    } while (fabs(fx) > epsilon && iteration < 1000);

    return x;
}

double diff(double x, double y) {
    return 6 * sin(x) - (3 + x) * y;
}

double runge_kutta_step(double x, double y, double h) {
    double k1, k2, k3, k4;
    
    k1 = diff(x, y);
    k2 = diff(x + h/2, y + h*k1/2);
    k3 = diff(x + h/2, y + h*k2/2);
    k4 = diff(x + h, y + h*k3);
    
    return y + h * (k1 + 2*k2 + 2*k3 + k4) / 6;
}

int step_count;
double solveODE(double x0, double y0, double x_end, double epsilon) {
    double x = x0;
    double y = y0;
    double h = 1.0;
    step_count = 0;
    
    while (x < x_end) {

        if (x + h > x_end) {
            h = x_end - x;
        }
        
        double y1, y2, error;
        int adaptive_step = 0;
        
        do {
            y1 = runge_kutta_step(x, y, h);
            
            double y_temp = runge_kutta_step(x, y, h/2);
            y2 = runge_kutta_step(x + h/2, y_temp, h/2);

            error = fabs(y1 - y2) / 15.0;
            
            if (error > epsilon) {
                h /= 2;
                adaptive_step++;
                
                if (adaptive_step > 10) {
                    printf("Предупреждение: достигнуто максимальное число адаптаций шага\n");
                    break;
                }
            }
        } while (error > epsilon);
        
        double y_next = y2;
        
        y = y_next;
        x += h;

        step_count++;
        xr[step_count] = x;
        yr[step_count] = y;

        // if (error < epsilon / 32) {
        //     h *= 2;
        // }
    }
    
    // printf("\nВсего шагов: %d\n", step_count);
    //printf("Финальная точка: y(%.6f) = %.6f\n", x, y);
    return h;
}

int findLower(double x) {
    int i = 0;
    for (i = 1; i < step_count; i++) {
        if (xr[i] >= x) break;
    }
    i--;
    //printf("%d ", i);
    return i;
}

int findHigher(double x) {
    return (findLower(x) + 1);
}

double findQ (double x) {
    double xi = xr[findLower(x)];
    return (x - xi) / h;
}

int main () {
    double a = 2.0;  
    double b = 3.0; 
    double epsilon = 0.001;
    
    double k = chordMethod(a, b, epsilon);
    double x0 = 0.0; 
    double x_end = 2.0;
   
    
    printf("\nНайден корень: %.4f  за %d итераций\n", k, iteration);
    printf("Решениe ОДУ методом Рунге-Кутта 4-го порядка\n");
    printf("|    x    |  y_прибл  |\n");

    xr[0] = xi[0] = x0;
    yr[0] = yi[0] = k;

    h = solveODE(xi[0], yi[0], x_end, 0.0001);
    for (int i = 1; i <= step_count; i++) {
        printf("| %7.4f | %9.4f |\n",xr[i], yr[i]);
    }

    printf("Результаты линейной интерполяции\n");
    printf("|    x    |  y_прибл  |\n");
    double q = findQ(xi[0]);
    for (int i = 0; i < 21; i++) {
        xi[i] = 0.1 * i;
        q = findQ(xi[i]);
        yi[i] = yr[findLower(xi[i])] + q * (yr[findHigher(xi[i])] - yr[findLower(xi[i])]);
        printf("| %7.4f | %9.5f |\n", xi[i], yi[i]);
        

    }


    double qt = (yi[0] + yi[20] / 2);

    for (int i = 1; i < 20; i++) {
        qt += yi[i];
    }
    qt = qt * 0.1;

    printf("Найденное количество теплоты: %.4f\n", qt);

    return 0;
}