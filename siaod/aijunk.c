#include <stdio.h>
#include "aijunk.h"

// Вспомогательная функция для рекурсивного вывода
void printTreeRecursive(struct AVLNODE* node, int level, char* prefix, int isLeft) {
    if (node == NULL) return;
    
    // Вывод текущего узла
    printf("%s", prefix);
    printf("%s", isLeft ? "├── " : "└── ");
    printf("%d (b:%d)\n", node->data, node->balance);
    
    // Обновляем префикс для дочерних узлов
    char newPrefix[256];
    strcpy(newPrefix, prefix);
    strcat(newPrefix, isLeft ? "│   " : "    ");
    
    // Сначала правый потомок (сверху), затем левый (снизу)
    printTreeRecursive(node->right, level + 1, newPrefix, 1);
    printTreeRecursive(node->left, level + 1, newPrefix, 0);
}

// Основная функция вертикального вывода
void visualAVLTree(struct AVLNODE* root) {
    if (root == NULL) {
        printf("Дерево пустое!\n");
        return;
    }
    
    printf("\nВизуализация АВЛ дерева (вертикальный формат):\n");
    printf("══════════════════════════════════════════\n");
    
    // Начинаем с корня
    printTreeRecursive(root, 0, "", 0);
    
    printf("══════════════════════════════════════════\n\n");
}