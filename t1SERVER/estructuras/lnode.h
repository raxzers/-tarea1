//
// Created by gacova on 05/08/19.
//

#ifndef T1SERVER_LNODE_H
#define T1SERVER_LNODE_H


class lnode {
private:
    int data;
    lnode *nxt;
public:
    int getData() const;

    void setData(int data);

    lnode *getNxt() const;

    void setNxt(lnode *nxt);


};


#endif //T1SERVER_LNODE_H
