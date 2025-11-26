#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "pr1.h"
#include "pr4.h"
#include "rjin.h"

struct BNODE {
    int data;
    int balance;
    struct BNODE * left;
    struct BNODE * right;
};

void insertBTree(struct BNODE **, int);

int hr, vr;

int countSizeB (struct BNODE *root) {
    if (root == NULL) {
        return 0;
    } else return (1 + countSizeB(root->left) + countSizeB(root->right));
}

int averagePathB(struct BNODE *root, int l) {
    if (root == NULL) {
        return 0;
    } else return (l + averagePathB(root->left, (l + 1)) + averagePathB(root->right, (l + 1)));
}

double findAverageHeight (struct BNODE *root) {
    int path = averagePathB(root, 1);
    int size = countSizeB(root);
    float res = 1.0f * (path) / size;
    //printf("%4d %4d  %2.2f", path, size, res);
    return res;
}


void run_pr4 () {
    const int n1 = 10;
    int n2 = 50, n3 = 100, n4 = 200;
    createTable4(n1);
    printf("------------------------------------------------------\n");
    createTable4(n2);
    printf("------------------------------------------------------\n");
    createTable4(n3);
    printf("------------------------------------------------------\n");
    createTable4(n4);
    printf("------------------------------------------------------\n");

}

void createTable4 (int n) {
    int sorty[n]; 
    int sorty2[n], unsorty[n];
    // fill_mass(sorty, n, 0);
    // fill_mass(sorty2, n, 1);
    fill_mass(unsorty, n, 4);

    for (int i = 0; i < n; i++) {
        sorty[i] = unsorty[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (sorty[i] < sorty[j]) {
                int temp = sorty[j];
                sorty[j] = sorty[i];
                sorty[i] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        sorty2[i] = sorty[n - i - 1];
    }
    // printf("%d Массивы данных: \n", n);
    // print_mass(sorty, n);
    // print_mass(sorty2, n);
    // print_mass(unsorty, n);
    struct BNODE * root = NULL;

    
    double teorHeight = ((log((n + 1)) - 1) / log(2)) + 1;
    //double teorHeight = 2*log(n + 1);

    printf("Размер | Cp. Высота | Теор. оценка \n");

    printf("%7d|", n);
    hr = 1;
    vr = 1;
    for (int i = 0; i < n; i++) {
        insertBTree(&root, sorty[i]);
        // printf("After inserting %d:\n", sorty[i]);
        // printBTree(root, 0);
        // printf("---\n");
    };
    double anerageHeight = findAverageHeight(root);
    printf("%11.2f |%13.2f \n", anerageHeight, teorHeight);

    printf("%7d|", n);
    root = NULL;
    hr = 1;
    vr = 1;
    for (int i = 0; i < n; i++) {
        insertBTree(&root, sorty2[i]);
        // printf("After inserting %d:\n", sorty[i]);
        // printBTree(root, 0);
        // printf("---\n");
    };
    anerageHeight = findAverageHeight(root);
    printf("%11.2f |%13.2f \n", anerageHeight, teorHeight);

    printf("%7d|", n);
    root = NULL;
    hr = 1;
    vr = 1;
    for (int i = 0; i < n; i++) {
        insertBTree(&root, unsorty[i]);
        // printf("After inserting %d:\n", sorty[i]);
        // printBTree(root, 0);
        // printf("---\n");
    };
    anerageHeight = findAverageHeight(root);
    printf("%11.2f |%13.2f \n", anerageHeight, teorHeight);


}

void insertBTree(struct BNODE ** root, int data) {
    if (*root == NULL) {
        *root = malloc(sizeof(struct BNODE));
        (*root)->data = data;
        (*root)->balance = 0;
        (*root)->left = NULL;
        (*root)->right = NULL;
        vr = 1;
        return;
    } else if ((*root)->data > data){
        insertBTree(&(*root)->left, data);
        if (vr) {
            if ((*root)->balance == 0) {
                struct BNODE * q = (*root)->left;
                (*root)->left = q->right;
                q->right = (*root);
                (*root) = q;
                q->balance = 1;
                vr = 0;
                hr = 1;
            } else {
                (*root)->balance = 0;
                hr = 1;
            }
        } else {
            hr = 0;
        }
    } else if ((*root)->data < data) {
        insertBTree(&(*root)->right, data);
        if (vr) {
            (*root)->balance = 1;
            vr = 0;
            hr = 1;
        } else if (hr) {
            if ((*root)->balance > 0) {
                struct BNODE * q = (*root)->right;
                (*root)->right = q->left;
                (*root)->balance = 0;
                q->balance = 0;
                q->left = (*root);
                (*root) = q;
                vr = 1;
                hr = 0;
            } else {
                hr = 0;
            }
        }
    }
}
