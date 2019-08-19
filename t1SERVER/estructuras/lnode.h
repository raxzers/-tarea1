//
// Created by gacova on 05/08/19.
//

#ifndef T1SERVER_LNODE_H
#define T1SERVER_LNODE_H

/**
    *@brief  nodo para la lista
    *
    * */
class lnode {
private:
    /**
    *@brief  entero donde se guarda la informacion
    *
    * */
    int data;
    /**
    *@brief  nodo para el siguiente
    *
    * */
    lnode *nxt;
public:
    /**
    *@brief  metodo para obtener el valor
    *
    * */
    int getData() const;
/**
    *@brief  metodo para modificar el valor
    * @param data el valor para modificar
    * */
    void setData(int data);
/**
    *@brief  metodo para obtener el siguiente
    *
    * */
    lnode *getNxt() const;
/**
    *@brief  metodo para modificar el siguiente
    *@param nxt puntero para el siguiente
    * */
    void setNxt(lnode *nxt);


};


#endif //T1SERVER_LNODE_H
