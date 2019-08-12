//
// Created by gacova on 05/08/19.
//

#ifndef T1SERVER_LIST_H
#define T1SERVER_LIST_H


#include "lnode.h"

/**
 * @brief tomado y modificado de https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr
 * */


class list {
private:
    /**
     * @brief punero a la cabeza y la cola
     * **/
    lnode *head, *tail;
public:
    /**
     * @brief  constructor de la lista
     * **/
    list()
    {
        head= nullptr;
        tail= nullptr;
    }
    /**
     * @brief metodo para encontrar el valor en la posicion
     * @param pos posicion en la lista
     * @return el nuemero en esa posicion
     * **/
    int getPosi(int pos);
    /**
    * @brief metodo para insertar
    * @param value numero que se inserta
    * **/
    void insert_start(int value);
    /**
    * @brief metodo para cambiar el valor en una posicion espeficica
    * @param value numero con el que se va cambiar
     * @param pos posicion en la lista
    * **/
    void change_value(int pos, int value);
    /**
    * @brief metodo para eliminar el primero de la lista
    * **/
    void delete_first();
    /**
    * @brief metodo para mostrar lista en consola
    * **/
    void display();
};


#endif //T1SERVER_LIST_H
