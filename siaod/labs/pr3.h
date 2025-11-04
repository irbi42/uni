#ifndef PR3_H
#define PR3_H

struct AVLNODE {
    int data;
    int balance;
    struct AVLNODE *left;
    struct AVLNODE *right;
};

void run_pr3();
void createTable3 (int);
int addToAVL (int, struct AVLNODE **);
struct AVLNODE* LLturn(struct AVLNODE *);
struct AVLNODE* LRturn(struct AVLNODE *);
struct AVLNODE* RRturn(struct AVLNODE *);
struct AVLNODE* RLturn(struct AVLNODE *);

#endif