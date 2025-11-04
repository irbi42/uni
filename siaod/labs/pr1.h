#ifndef PR1_H
#define PR1_H

struct NODE {
    int data;
    struct NODE *left;
    struct NODE *right;
};

void run_pr1();
void printTree(struct NODE *);
int countSize (struct NODE *);
int countHeight(struct NODE *);
int countAverageHeight (struct NODE *);
int countCheckSum (struct NODE *);

#endif