
#ifndef PR3_H
#define PR3_H

struct AVLNODE {
    int data;
    int balance;
    struct AVLNODE *left;
    struct AVLNODE *right;
};

void run_pr4();
void createTable4 (int);


#endif