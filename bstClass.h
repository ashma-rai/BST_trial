#ifndef BSTCLASS_H
#define BSTCLASS_H
#include<iostream>
using namespace std;

class bstClass
{
    public:

struct node
{
    int data;
    node *left;
    node *right;
};
node *tree;

        bstClass();
        virtual ~bstClass();

        void insertElement(node*&, int);
        void preorder(node*);
        void inorder(node*);
        void postorder(node*);
        void searchElement(node*, int);
};

#endif // BSTCLASS_H
