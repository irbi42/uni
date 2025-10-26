#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "pr5.h"
#include "rjin.h"


void run_pr5 () {
    const int n1 = 10;
    int n2 = 50, n3 = 100, n4 = 200;
    createTable5(n1);
    printf("------------------------------------------------------\n");
    createTable5(n2);
    printf("------------------------------------------------------\n");
    createTable5(n3);
    printf("------------------------------------------------------\n");
    createTable5(n4);
}

void createTable5 (int n) {
    srand(time(NULL));
    int sorty[n]; 
    int unsorty[n];
    fill_mass(sorty, n, 0);
    fill_mass(unsorty, n, 4);
    // printf("%d Массивы данных: \n", n);
    // print_mass(sorty, n);
    // print_mass(sorty2, n);
    //print_mass(unsorty, n);
    DopNode * root = NULL;
    DopNode * values = malloc(n * sizeof(DopNode));
    double a1w, a2w;

    printf("Размер | Cp. Высота A1 | Cp. Высота A2 \n");
    printf("%7d|", n);

    for (int i = 0; i < n; i++) {
        values[i].data = sorty[i];
        values[i].weight = i;
    };

    root = createDOP1(values, n);
    a1w = countAverageWeightHeight(root);

    //visualDOPTree(root);

    root = createDOP2(values, n);
    a2w = countAverageWeightHeight(root);

    //visualDOPTree(root);
    
    printf("%14.3f |%14.3f \n", a1w, a2w);

//----------------------------------------
    
    printf("%7d|", n);

    for (int i = 0; i < n; i++) {
        values[i].data = unsorty[i];
        values[i].weight = rand()%100;
    };

    root = createDOP1 (values, n);
    a1w = countAverageWeightHeight(root);
    
    //visualDOPTree(root);

    root = createDOP2(values, n);
    a2w = countAverageWeightHeight(root);

    //visualDOPTree(root);
    printf("%14.3f |%14.3f \n", a1w, a2w);
    
}

void quick_sort (DopNode * mass, int *indexes, int n)
{
    int left = 0;
    int right = n - 1;
    int x = mass[indexes[left]].weight;
    int i = left;
    int j = right;

    while (!(i > j))
    {
        while (mass[indexes[i]].weight < x && i < right) 
        {
            i++;
        }
        while (mass[indexes[j]].weight >= x && j > left) 
        {
            j--;
        }
        if (i <= j)
        {
            int t = indexes[i];
            indexes[i] = indexes[j];
            indexes[j] = t;
            i++;
            j--;
        }
        
    }
    if (left < j) quick_sort(mass, &indexes[left], j + 1);
    if (i < right) quick_sort(mass, &indexes[i], right - i + 1);

    return;
}

int countWeight (DopNode *root) {
    if (root == NULL) {
        return 0;
    } else return (root->weight + countWeight(root->left) + countWeight(root->right));
}

int countWeightHight(DopNode *root, int height) {
    if (root == NULL) {
        return 0;
    } else return (height * root->weight + countWeightHight(root->left, (height + 1)) + countWeightHight(root->right, (height + 1)));
}

double countAverageWeightHeight (DopNode *root) {
    return (double)countWeightHight(root, 1)/countWeight(root);
}

void addNode (DopNode **root, DopNode * value) {
    if (*root == NULL) {
        *root = malloc(sizeof(DopNode));
        (*root)->data = value->data;
        (*root)->weight = value->weight;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    if (value->data < (*root)->data) {
        addNode(&(*root)->left, value);
    }
    else if (value->data > (*root)->data) {
        addNode(&(*root)->right, value);
    }
    return;
}

DopNode * createDOP1 (DopNode * value, int n) {
    DopNode * root = NULL;
    for (int i = 0; i < n; i++) {
        value[i].use = 0;
    };
    for (int i = 0; i < n; i++) {
        int max = 0;
        int index = 0;
        for (int j = 0; j < n; j++){
            if ((value[j].weight > max) && !value[j].use) {
                max = value[j].weight;
                index = j;
            }
        }
        value[index].use = 1;
        addNode (&root, &value[index]);

        // printf("After inserting %d:\n", value[index].data);
        // visualDOPTree(root);
        // printf("---\n");
    };

    return root;
}

void Dop2FromIndexed (DopNode **root, DopNode * value, int * indexes, int left, int right) {
    double weight = 0;
    int sum = 0;
    
    if (left <= right) {
        int index = left;
        for (int i = left; i <= right; i++) {
            weight = weight + value[indexes[i]].weight;
        }
        for (int i = left; i < right; i++) {
            if ((sum < (int)(ceil(weight / 2))) && ((sum + value[indexes[i]].weight) >= (int)(ceil(weight / 2)))) {
                break;
            }
            sum = sum + value[indexes[i]].weight;
            index = i;
        }
        addNode (root, &(value[indexes[index]]));
        Dop2FromIndexed (root, value, indexes, left, index - 1);
        Dop2FromIndexed (root, value, indexes, (index + 1), right);
    }
}

DopNode * createDOP2 (DopNode * value, int n) {
    DopNode * root = NULL;
    int * indexes = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        indexes[i] = i;
    }
    quick_sort(value, indexes, n);
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", value[indexes[i]].weight);
    // }
    // printf("\n");
    Dop2FromIndexed(&root, value, indexes, 0, n - 1);

    return root;
}


void printTreeRecursive(DopNode* node, int level, char* prefix, int isLeft) {
    if (node == NULL) return;
    
    printf("%s", prefix);
    printf("%s", isLeft ? "├── " : "└── ");
    printf("%d (w:%d)\n", node->data, node->weight);
    
    char newPrefix[256];
    strcpy(newPrefix, prefix);
    strcat(newPrefix, isLeft ? "│   " : "    ");
    
    printTreeRecursive(node->right, level + 1, newPrefix, 1);
    printTreeRecursive(node->left, level + 1, newPrefix, 0);
}

void visualDOPTree(DopNode * root) {
    if (root == NULL) {
        printf("Дерево пустое!\n");
        return;
    }
    
    printf("══════════════════════════════════════════\n");
    printTreeRecursive(root, 0, "", 0);
    printf("══════════════════════════════════════════\n\n");
}