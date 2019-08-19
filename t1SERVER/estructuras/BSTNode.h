//
// Created by gacova on 05/08/19.
//

#ifndef T1SERVER_BSTNODE_H
#define T1SERVER_BSTNODE_H
/**
    *@brief  nodo para el arbol
    *
    * */

class BSTNode {
public:
    /**
    *@brief  entero donde se guarda la informacion
    *
    * */
    int info;
    /**
       *@brief  puntero para el nodo izquierdo
       *
       * */
    BSTNode *left;
    /**
    *@brief  puntero para el nodo derecho
    *
    * */
    BSTNode *right;
};


#endif //T1SERVER_BSTNODE_H
