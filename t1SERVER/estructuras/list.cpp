//
// Created by gacova on 05/08/19.
//

#include <iostream>
#include "list.h"

void list::insert_start(int value) {
    lnode *temp=new lnode;
    temp->setData(value);
    temp->setNxt(head);
    head=temp;
}

void list::delete_first() {
    lnode *temp=head;
    head=head->getNxt();
    delete temp;
}

void list::change_value(int pos, int value) {
    lnode *cur=head;
    for(int i=1;i<pos;i++)
    {
        cur=cur->getNxt();
    }
    cur->setData(value);

}

void list::display() {
    lnode *temp=head;
    while(temp!= nullptr)
    {
        std::cout<<temp->getData()<<"\t";
        temp=temp->getNxt();
    }
    std::cout<<std::endl;
}

int list::getPosi(int pos) {
    lnode *cur=head;
    for(int i=1;i<pos;i++)
    {
        cur=cur->getNxt();
    }
    return cur->getData();
}
