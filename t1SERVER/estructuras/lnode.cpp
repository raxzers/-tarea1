//
// Created by gacova on 05/08/19.
//

#include "lnode.h"
int lnode::getData() const {
    return data;
}

void lnode::setData(int data) {
    lnode::data = data;
}

lnode *lnode::getNxt() const {
    return nxt;
}

void lnode::setNxt(lnode *nxt) {
    lnode::nxt = nxt;
}