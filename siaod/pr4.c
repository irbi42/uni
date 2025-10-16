#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "pr1.h"
#include "pr4.h"
#include "rjin.h"

const int m = 2;
struct BNode {
    int data;
    struct Bpage * p;
};
struct Bpage {
    int k;
    struct Bpage * p0;
    struct BNode elements [2 * m + 1];
};


void run_pr3 () {
    const int n1 = 10;
    //int n2 = 50, n3 = 100, n4 = 200;
    createTable3(n1);
    printf("------------------------------------------------------\n");
    //createTable3(n2);
    printf("------------------------------------------------------\n");
    //createTable3(n3);
    printf("------------------------------------------------------\n");
    //createTable3(n4);
}

void createTable3 (int n) {
    int sorty[n]; 
    //int sorty2[n], unsorty[n];
    fill_mass(sorty, n, 0);
    //fill_mass(sorty2, n, 1);
    //fill_mass(unsorty, n, 4);
    // printf("%d Массивы данных: \n", n);
    // print_mass(sorty, n);
    // print_mass(sorty2, n);
    // print_mass(unsorty, n);
    int m = 3; 

    printf("Размер | Cp. Высота | Теор. оценка \n");
    printf("%7d|", n);

}

struct BNode * Bsearch (int data, struct Bpage * a) {
    if(a == NULL) return NULL;
    else {
        int l = 1;
        int r = a->k + 1;
        while (l < r) {
            int i = (l + r) / 2;
            if (a->elements[i].data <= data) {
                l++;
            } else  r = i;
        }
        r--;
        if (r > 0 && a->elements[r].data == data) {
            struct BNode * result = &(a->elements[r]);
        } else {
            if (r == 0) {
                Bsearch(data, a->p0);
            } else {
                Bsearch(data, a->elements[r].p);
            }
        }
    }
}