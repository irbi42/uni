#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "pr1.h"
#include "pr3.h"
#include "rjin.h"

float turns = 0;
//rts.sit@mail.ru

int countSizeAVL (struct AVLNODE *root) {
    if (root == NULL) {
        return 0;
    } else return (1 + countSizeAVL(root->left) + countSizeAVL(root->right));
}

int averagePath(struct AVLNODE *root, int l) {
    if (root == NULL) {
        return 0;
    } else return (l + averagePath(root->left, (l + 1)) + averagePath(root->right, (l + 1)));
}

float averageHeight (struct AVLNODE *root) {
    int path = averagePath(root, 1);
    int size = countSizeAVL(root);
    float res = 1.0f * (path) / size;
    //printf("%4d %4d  %2.2f", path, size, res);
    return res;
}

void run_pr3 () {
    const int n1 = 10;
    int n2 = 50, n3 = 100, n4 = 200;
    createTable3(n1);
    printf("-----------------------------------------------------------\n");
    createTable3(n2);
    printf("-----------------------------------------------------------\n");
    createTable3(n3);
    printf("-----------------------------------------------------------\n");
    createTable3(n4);
    printf("-----------------------------------------------------------\n");
}

void createTable3 (int n) {
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

    printf("Размер | Высота АВЛ |   Теор. оценка   | Ср. Кол. Поворотов  \n");
    printf("%7d|", n);

    float teorHeightMax = 1.44 * log2f(n + 2) - 1;

    struct AVLNODE *avl = NULL;
    turns = 0;
    int added = 0;
    for (int i = 0; i < n; i++) {
        added = addToAVL(sorty[i], &avl);
    };
    if(added){};
    turns = turns / n;
    float treeHeight = averageHeight(avl);

    printf("%10.3f  |    h < %5.2f    |%8.2f\n", treeHeight, teorHeightMax, turns);

    avl = NULL;
    turns = 0;
    for (int i = 0; i < n; i++) {
        added = addToAVL(sorty2[i], &avl);
    };
    turns = turns / n;
    treeHeight = averageHeight(avl);

    printf("%7d|", n);
    printf("%10.3f  |     h < %5.2f    |%8.2f\n", treeHeight, teorHeightMax, turns);


    avl = NULL;
    turns = 0;
    for (int i = 0; i < n; i++) {
        added = addToAVL(unsorty[i], &avl);
    };
    turns = turns / n;
    treeHeight = averageHeight(avl);
    printf("%7d|", n);
    printf("%10.3f  |     h < %5.2f    |%8.2f\n", treeHeight, teorHeightMax, turns);

    return;
}

int addToAVL(int d, struct AVLNODE **root) {
    int growth = 0;
    
    if (*root == NULL) {
        *root = malloc(sizeof(struct AVLNODE));
        if (*root == NULL) {
            return 0;
        }
        (*root)->data = d;
        (*root)->balance = 0;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return 1;
    }
    
    if (d < (*root)->data) {
        growth = addToAVL(d, &(*root)->left);
        if (growth) {
            switch ((*root)->balance) {
                case 1:
                    (*root)->balance = 0;
                    growth = 0;
                    break;
                case 0:  
                    (*root)->balance = -1;
                    growth = 1;
                    break;
                case -1:
                    if ((*root)->left->balance == -1) {
                        
                        *root = LLturn(*root);
                        turns++;
                    } else {
                        
                        *root = LRturn(*root);
                        turns++;
                    }
                    growth = 0;
                    break;
            }
        }
    }
    else if (d > (*root)->data) {
        growth = addToAVL(d, &(*root)->right);
        if (growth) {
            switch ((*root)->balance) {
                case -1: 
                    (*root)->balance = 0;
                    growth = 0;
                    break;
                case 0:  
                    (*root)->balance = 1;
                    growth = 1;
                    break;
                case 1:  
                    if ((*root)->right->balance == 1) {
                        *root = RRturn(*root);
                        turns++;
                    } else {
                        *root = RLturn(*root);
                        turns++;
                    }
                    growth = 0;
                    break;
            }
        }
    }
    else {
        growth = 0;
    }
    
    return growth;
}

struct AVLNODE* LLturn(struct AVLNODE* root) {
    struct AVLNODE* newRoot = root->left;
    struct AVLNODE* temp = newRoot->right;
    
    newRoot->right = root;
    root->left = temp;

    if (newRoot->balance == -1) {
        newRoot->balance = 0;
        root->balance = 0;
    } else { 
        newRoot->balance = 1;
        root->balance = -1;
    }
    
    return newRoot;
}

struct AVLNODE* RRturn(struct AVLNODE* root) {
    struct AVLNODE* newRoot = root->right;
    struct AVLNODE* temp = newRoot->left;
    
    newRoot->left = root;
    root->right = temp;
    

    if (newRoot->balance == 1) {
        newRoot->balance = 0;
        root->balance = 0;
    } else {
        newRoot->balance = -1;
        root->balance = 1;
    }
    
    return newRoot;
}

struct AVLNODE* LRturn(struct AVLNODE* root) {
    struct AVLNODE* B = root->left;
    struct AVLNODE* C = B->right;
    
    B->right = C->left;
    C->left = B;
    root->left = C->right;
    C->right = root;
    
    if (C->balance == -1) {
        root->balance = 1;
        B->balance = 0;
    } else if (C->balance == 0) {
        root->balance = 0;
        B->balance = 0;
    } else {
        root->balance = 0;
        B->balance = -1;
    }
    C->balance = 0;
    
    return C;
}

struct AVLNODE* RLturn(struct AVLNODE* root) {
    struct AVLNODE* B = root->right;
    struct AVLNODE* C = B->left;
    
    B->left = C->right;
    C->right = B;
    root->right = C->left;
    C->left = root;
    
    if (C->balance == 1) {
        root->balance = -1;
        B->balance = 0;
    } else if (C->balance == 0) {
        root->balance = 0;
        B->balance = 0;
    } else { 
        root->balance = 0;
        B->balance = 1;
    }
    C->balance = 0;
    
    return C;
}


