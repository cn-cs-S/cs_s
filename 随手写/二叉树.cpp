#include<iostream>
#include<string>

struct tree
{
    tree *lchild;
    tree *rchild;
    std::string data;
    tree()
    {
        lchild=rchild=NULL;
    }
};
