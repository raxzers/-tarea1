//
// Created by gacova on 05/08/19.
//

#ifndef T1SERVER_BST_H
#define T1SERVER_BST_H


#include "BSTNode.h"

/**
 * @brief tomado y modificado de https://www.sanfoundry.com/cpp-program-implement-binary-tree-2/
 * */

class BST {
private:
    void find(int, BSTNode **, BSTNode **);

    void insert(BSTNode *, BSTNode *);
    void case_a(BSTNode *,BSTNode *);

    void case_b(BSTNode *,BSTNode *);

    void case_c(BSTNode *,BSTNode *);


    void display(BSTNode *, int);
    BSTNode *root;
public:

void insert(int num);



void del(int);


void display();

BST()

{

    root = nullptr;

}
};



#endif //T1SERVER_BST_H
