
#ifndef PR4_H
#define PR4_H

#define M 2

struct BNode {
    int data;
    struct Bpage * p;
};
struct Bpage {
    int k;
    struct Bpage * p0;
    struct BNode e [2 * M];
};

void run_pr4();
void createTable4 (int);
void insertBTree(struct Bpage **, int);


#endif