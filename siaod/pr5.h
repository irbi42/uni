#ifndef PR5_H
#define PR5_H

typedef struct DopNode {
    int data;
    int weight;
    int use;
    struct DopNode *left;
    struct DopNode *right;
} DopNode;

void run_pr5();
void createTable5 (int);
DopNode * createDOP1 (DopNode *, int);
DopNode * createDOP2 (DopNode *, int);
double countAverageWeightHeight (DopNode *);
void visualDOPTree(DopNode *);


#endif