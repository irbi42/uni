#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "pr1.h"
#include "pr4.h"
#include "rjin.h"

//для тестов, закоментить после проверки
void printBTree(struct Bpage * root, int level) {
    if (root == NULL) return;
    
    printf("Level %d (%d elements): ", level, root->k);
    for (int i = 0; i < root->k; i++) {
        printf("%d ", root->e[i].data);
    }
    printf("\n");
    
    if (root->p0 != NULL) {
        printf("  Left child: ");
        printBTree(root->p0, level + 1);
    }
    
    for (int i = 0; i < root->k; i++) {
        if (root->e[i].p != NULL) {
            printf("  Child after %d: ", root->e[i].data);
            printBTree(root->e[i].p, level + 1);
        }
    }
}

void calculateHeightSum(struct Bpage* root, int currentDepth, int* totalHeightSum, int* totalElements) {
    if (root == NULL) return;

    for (int i = 0; i < root->k; i++) {
        (*totalHeightSum) += currentDepth;
        (*totalElements) += 1;
    }

    if (root->p0 != NULL) {
        calculateHeightSum(root->p0, currentDepth + 1, totalHeightSum, totalElements);
    }
    
    for (int i = 0; i < root->k; i++) {
        if (root->e[i].p != NULL) {
            calculateHeightSum(root->e[i].p, currentDepth + 1, totalHeightSum, totalElements);
        }
    }
}

double findAverageHeight(struct Bpage * root) {
    if (root == NULL) return 0.0;
    
    int totalHeightSum = 0;
    int totalElements = 0;
    
    calculateHeightSum(root, 1, &totalHeightSum, &totalElements);
    
    if (totalElements == 0) return 0.0;
    
    return (double)totalHeightSum / totalElements;
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
}

void createTable4 (int n) {
    int sorty[n]; 
    int sorty2[n], unsorty[n];
    fill_mass(sorty, n, 0);
    fill_mass(sorty2, n, 1);
    fill_mass(unsorty, n, 4);
    // printf("%d Массивы данных: \n", n);
    // print_mass(sorty, n);
    // print_mass(sorty2, n);
    // print_mass(unsorty, n);
    struct Bpage * root = NULL;

    
    double teorHeight = ((log((n + 1)) - 1) / log((M + 1))) + 1;

    printf("Размер | Cp. Высота | Теор. оценка \n");
    printf("%7d|", n);

    for (int i = 0; i < n; i++) {
        insertBTree(&root, sorty[i]);
        // printf("After inserting %d:\n", sorty[i]);
        // printBTree(root, 0);
        // printf("---\n");
    };
    double anerageHeight = findAverageHeight(root);
    printf("%11.3f |%13.3f \n", anerageHeight, teorHeight);

    printf("%7d|", n);

    for (int i = 0; i < n; i++) {
        insertBTree(&root, sorty2[i]);
        // printf("After inserting %d:\n", sorty[i]);
        // printBTree(root, 0);
        // printf("---\n");
    };
    anerageHeight = findAverageHeight(root);
    printf("%11.3f |%13.3f \n", anerageHeight, teorHeight);

    printf("%7d|", n);

    for (int i = 0; i < n; i++) {
        insertBTree(&root, unsorty[i]);
        // printf("After inserting %d:\n", sorty[i]);
        // printBTree(root, 0);
        // printf("---\n");
    };
    anerageHeight = findAverageHeight(root);
    printf("%11.3f |%13.3f \n", anerageHeight, teorHeight);


}

int findPosition(struct Bpage * a, int D) {
    int R = 0;
    while (R < a->k && a->e[R].data < D) {
        R++;
    }
    return R;
}

void buildBTree(int D, struct Bpage * a, int * Rost, struct BNode * V) {
    struct BNode u;
    
    if (a == NULL) {
        V->data = D;
        V->p = NULL;
        *Rost = 1;
        return;
    }
    
    int R = findPosition(a, D);
    
    if (R < a->k && a->e[R].data == D) {
        *Rost = 0;
        return;
    } 
    struct Bpage * nextPage = (R == 0) ? a->p0 : a->e[R-1].p;
    buildBTree(D, nextPage, Rost, &u);
        
    if (!(*Rost)) {
        return;
    }
    
    if (a->k < 2 * M) {
        *Rost = 0;
        for (int i = a->k; i > R; i--) {
            a->e[i] = a->e[i-1];
        }
        a->e[R] = u;
        a->k++;
    } else {
        struct Bpage * b = malloc(sizeof(struct Bpage));
        b->k = 0;
        b->p0 = NULL;
        for (int i = 0; i < 2*M; i++) {
            b->e[i].p = NULL;
        }
        
        if (R <= M) {
            if (R == M) {
                *V = u;
            } else {
                *V = a->e[M-1];
                for (int i = M-1; i > R; i--) {
                    a->e[i] = a->e[i-1];
                }
                a->e[R] = u;
            }
            
            for (int i = 0; i < M; i++) {
                b->e[i] = a->e[i + M];
                b->k++;
            }
        } else {
            int newR = R - M - 1;
            *V = a->e[M];

            for (int i = 0; i < newR; i++) {
                b->e[i] = a->e[i + M + 1];
                b->k++;
            }
            
            b->e[newR] = u;
            b->k++;
            
            for (int i = newR + 1; i < M; i++) {
                b->e[i] = a->e[i + M];
                b->k++;
            }
        }

        a->k = M;
        b->p0 = V->p;
        V->p = b;
        *Rost = 1;
    }
}

struct Bpage * createPage() {
    struct Bpage * page = malloc(sizeof(struct Bpage));
    page->k = 0;
    page->p0 = NULL;
    for (int i = 0; i < 2*M; i++) {
        page->e[i].p = NULL;
        page->e[i].data = 0;
    }
    return page;
}


void insertBTree(struct Bpage ** root, int data) {
    int Rost = 0;
    struct BNode V;
    
    if (*root == NULL) {
        *root = createPage();
        (*root)->e[0].data = data;
        (*root)->k = 1;
        return;
    }
    
    buildBTree(data, *root, &Rost, &V);
    
    if (Rost) {
        struct Bpage * newRoot = createPage();
        newRoot->e[0] = V;
        newRoot->k = 1;
        newRoot->p0 = *root;
        *root = newRoot;
    }
}
