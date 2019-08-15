//
// Created by gacova on 05/08/19.
//

#ifndef T1SERVER_LNODE_H
#define T1SERVER_LNODE_H


class lnode {
private:
    /**
     * @brief varaible del amacenamiento
     * **/
    int data;
    /**
     * @brief puntero a siguiente
     * **/
    lnode *nxt;
public:
    /**
     * @brief metodo para obtener la informacion
     * **/
    int getData() const;
/**
     * @brief metodo para establecer la informacion
     * **/
    void setData(int data);
/**
     * @brief metodo para obtener el siguiente
     * **/
    lnode *getNxt() const;
/**
     * @brief metodo para establecer el siguiente
     * **/
    void setNxt(lnode *nxt);


};


#endif //T1SERVER_LNODE_H
