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
/**
 * @brief metodo busqueda
 * @param par puntero del padre
 * @param loc puntero del local
 * **/

    void find(int item, BSTNode **par, BSTNode **loc);
/**
 * @brief metodo auxiliar para la insecion
 * @param tree arbol actual
 * @param newBSTNode nuevo dodo
 * **/

    void insert(BSTNode *tree, BSTNode *newBSTNode);
/**
 * @brief elimina un nodo sin hijos
 * @param loc local
 * @param par padre
 * **/
    void case_a(BSTNode *par, BSTNode *loc);
/**
 * @brief elimina un nodo con un hijo
 * @param loc local
 * @param par padre
 * **/
    void case_b(BSTNode *par, BSTNode *loc);
/**
 * @brief elimina un nodo con dos hijos
 * @param loc local
 * @param par padre
 * **/

    void case_c(BSTNode *par,BSTNode *loc);

/**
 * @brief metodo auxiliar para la mostrar el arbol
 * @param ptr puntero del nodo del arbol
 * @param level nivel del arbol
 * **/
    void display(BSTNode *ptr, int level);
    BSTNode *root;
public:
/**
 * @brief metodo publico para la insecion
 * @param num numero que se inserta
 * **/
void insert(int num);

/**
 * @brief metodo publico para la eliminacion
 * @param num numero que se elimina
 * **/

void del(int item);

/**
 * @brief metodo publico para la mostrar el arbol
 * **/

void display();

/**
 * @brief constructor del arbol
 * **/

BST()

{

    root = nullptr;

}
};



#endif //T1SERVER_BST_H
