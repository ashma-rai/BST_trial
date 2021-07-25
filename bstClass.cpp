#include "bstClass.h"
bstClass::bstClass()
{
    //ctor
    tree=nullptr;
}

bstClass::~bstClass()
{
    //dtor
}

 void bstClass::insertElement(node* &root, int val)
    {
        if(root == nullptr)
        {
            node *temp = new node;
            temp->data = val;
            root = temp;
            root->left = nullptr;
            root->right = nullptr;
            cout<<"if ";
        }
        else
        {
            if(val < root->data)
            {
                insertElement(root->left, val);
                cout<<" else if ";
            }
            else
            {
                insertElement(root->right, val);
                cout<<" else else ";
            }
        }

    }

    void bstClass:: preorder(node *root)
    {
        if(root != nullptr)
        {
            std::cout << root->data <<"  ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void bstClass::inorder(node *root)
    {
        if(root != nullptr)
        {
            preorder(root->left);
            std::cout << root->data <<"  ";
            preorder(root->right);
        }
    }

    void bstClass::postorder(node *root)
    {
        if(root != nullptr)
        {
            preorder(root->left);
            preorder(root->right);
            std::cout << root->data <<"  ";
        }
    }

    void bstClass::searchElement(node *root, int val)
    {
        if(root == nullptr)
        {
            std::cout<<val<<"  is not present\n";
        }
        else if(root->data == val)
        {
            std::cout<<val<<"  is present\n";
        }
        else
        {
            if(val < root->data)
                searchElement(root->left, val);
            else
                searchElement(root->right, val);
        }
    }
