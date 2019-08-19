//
// Created by gacova on 05/08/19.
//

#include <iostream>
#include "BST.h"
using namespace std;
void BST::find(int item, BSTNode **par, BSTNode **loc)

{

    BSTNode *ptr, *ptrsave;

    if (root == nullptr)

    {

        *loc = nullptr;

        *par = nullptr;

        return;

    }

    if (item == root->info)

    {

        *loc = root;

        *par = nullptr;

        return;

    }

    if (item < root->info)

        ptr = root->left;

    else

        ptr = root->right;

    ptrsave = root;

    while (ptr != nullptr)

    {

        if (item == ptr->info)

        {

            *loc = ptr;

            *par = ptrsave;

            return;

        }

        ptrsave = ptr;

        if (item < ptr->info)

            ptr = ptr->left;

        else

            ptr = ptr->right;

    }

    *loc = nullptr;

    *par = ptrsave;

}



/*

 * Inserting Element into the Tree

 */

void BST::insert(BSTNode *tree, BSTNode *newBSTNode)

{

    if (root == nullptr)

    {

        root = new BSTNode;

        root->info = newBSTNode->info;

        root->left = nullptr;

        root->right = nullptr;

        std::cout<<"Root Node is Added"<<endl;

        return;

    }

    if (tree->info == newBSTNode->info)

    {

        cout<<"Element already in the tree"<<endl;

        return;

    }

    if (tree->info > newBSTNode->info)

    {

        if (tree->left != nullptr)

        {

            insert(tree->left, newBSTNode);

        }

        else

        {

            tree->left = newBSTNode;

            (tree->left)->left = nullptr;

            (tree->left)->right = nullptr;

            cout<<"Node Added To Left"<<endl;

            return;

        }

    }

    else

    {

        if (tree->right != nullptr)

        {

            insert(tree->right, newBSTNode);

        }

        else

        {

            tree->right = newBSTNode;

            (tree->right)->left = nullptr;

            (tree->right)->right = nullptr;

            cout<<"Node Added To Right"<<endl;

            return;

        }

    }

}



/*

 * Delete Element from the tree

 */

void BST::del(int item)

{

    BSTNode *parent, *location;

    if (root == nullptr)

    {

        cout<<"Tree empty"<<endl;

        return;

    }

    find(item, &parent, &location);

    if (location == nullptr)

    {

        cout<<"Item not present in tree"<<endl;

        return;

    }

    if (location->left == nullptr && location->right == nullptr)

        case_a(parent, location);

    if (location->left != nullptr && location->right == nullptr)

        case_b(parent, location);

    if (location->left == nullptr && location->right != nullptr)

        case_b(parent, location);

    if (location->left != nullptr && location->right != nullptr)

        case_c(parent, location);

    free(location);

}



/*

 * Case A

 */

void BST::case_a(BSTNode *par, BSTNode *loc )

{

    if (par == nullptr)

    {

        root = nullptr;

    }

    else

    {

        if (loc == par->left)

            par->left = nullptr;

        else

            par->right = nullptr;

    }

}



/*

 * Case B

 */

void BST::case_b(BSTNode *par, BSTNode *loc)

{

    BSTNode *child;

    if (loc->left != nullptr)

        child = loc->left;

    else

        child = loc->right;

    if (par == nullptr)

    {

        root = child;

    }

    else

    {

        if (loc == par->left)

            par->left = child;

        else

            par->right = child;

    }

}



/*

 * Case C

 */

void BST::case_c(BSTNode *par, BSTNode *loc)

{

    BSTNode *ptr, *ptrsave, *suc, *parsuc;

    ptrsave = loc;

    ptr = loc->right;

    while (ptr->left != nullptr)

    {

        ptrsave = ptr;

        ptr = ptr->left;

    }

    suc = ptr;

    parsuc = ptrsave;

    if (suc->left == nullptr && suc->right == nullptr)

        case_a(parsuc, suc);

    else

        case_b(parsuc, suc);

    if (par == nullptr)

    {

        root = suc;

    }

    else

    {

        if (loc == par->left)

            par->left = suc;

        else

            par->right = suc;

    }

    suc->left = loc->left;

    suc->right = loc->right;

}

/*

 * Display Tree Structure

 */

void BST::display(BSTNode *ptr, int level)

{

    int i;

    if (ptr != nullptr)

    {

        display(ptr->right, level+1);

        cout<<endl;

        if (ptr == root)

            cout<<"Raiz->:  ";

        else

        {

            for (i = 0;i < level;i++)

                cout<<"       ";

        }

        cout<<ptr->info;

        display(ptr->left, level+1);

    }
        cout<<endl;
}

void BST::insert(int num) {
    BSTNode *temp = new BSTNode;

    temp->info=num;

    this->insert(root, temp);
}

void BST::display() {

    display(root,1);
    cout<< "salio display"<<endl;
}
