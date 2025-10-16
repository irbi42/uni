#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pr1.h"


void run_pr1 () {
    printf("Размещаем дерево со следующими данными:  ");
    // разместить дерево в памяти и запомнить случайными числами
    struct NODE root;
    root.left = NULL;
    root.right = NULL;

    srand(time(NULL));
    root.data = rand()%20 - 8;
    printf("%3d ", root.data);

    struct NODE *temp = malloc(sizeof(struct NODE));
    temp->data = rand()%20 - 8;
    root.left = temp;
    printf("%3d ", root.left->data);

    temp = malloc(sizeof(struct NODE));
    temp->data = rand()%20 - 8;
    root.left->left = temp;
    root.left->left->left = NULL;
    printf("%3d ", root.left->left->data);

    temp = malloc(sizeof(struct NODE));
    temp->data = rand()%20 - 8;
    root.left->left->right = temp;
    root.left->left->right->right = NULL;
    printf("%3d ", root.left->left->right->data);

    temp = malloc(sizeof(struct NODE));
    temp->data = rand()%20 - 8;
    root.left->left->right->left = temp;
    root.left->left->right->left->left = NULL;
    root.left->left->right->left->right = NULL;
    printf("%3d ", root.left->left->right->left->data);

    temp = malloc(sizeof(struct NODE));
    temp->data = rand()%20 - 8;
    root.left->right = temp;
    root.left->right->left = NULL;
    root.left->right->right = NULL;
    printf("%3d ", root.left->right->data);
    printf("\n");



    // написать функции вычисления

    // размера дерева
    int size = countSize(&root);
    // высоты дерева
    int height = countHeight(&root);
    // средней высоты дерева
    int avrHeight = countAverageHeight(&root);
    // контрольной суммы
    int checkSum = countCheckSum (&root);
    // проверить и вывести на экран
    printf("Результаты вычислений для построенного дерева: \n Размер дерева: %d \n Высота дерева: %d \n Средняя высота дерева: %d \n Контрольная сумма: %d \n", size, height, avrHeight, checkSum);
    // написать обход слева направо и вывести на экран
    printf("Обход дерева слева направо: ");
    printTree(&root);
    
    return;
}

void printTree(struct NODE *root) {
    if (root != NULL) {
        printTree(root->left);
        printf("%3d ", root->data);
        printTree(root->right);
    }
    return;
}

int countSize (struct NODE *root) {
    if (root == NULL) {
        return 0;
    } else return (1 + countSize(root->left) + countSize(root->right));
}

int countHeight(struct NODE *root) {
    if (root == NULL) {
        return 0;
    } else {
        int a = countHeight(root->left);
        int b = countHeight(root->right);
    return 1 + ((a > b) ? a : b);
    }
}

int countAveragePath(struct NODE *root, int l) {
    if (root == NULL) {
        return 0;
    } else return (l + countAveragePath(root->left, (l + 1)) + countAveragePath(root->right, (l + 1)));
}

int countAverageHeight (struct NODE *root) {
    return countAveragePath(root, 1)/countSize(root);
}

int countCheckSum (struct NODE *root) {
    if (root == NULL) {
        return 0;
    } else return (root->data + countCheckSum(root->left) + countCheckSum(root->right));
}