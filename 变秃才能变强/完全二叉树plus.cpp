#include<iostream>
#include<queue>
using namespace std;

struct Tree {
    int data;
    Tree *lchild;
    Tree *rchild;
};

void creat(Tree *&T, int &num) {
    queue<Tree*> Q;
    T = new Tree();
    Q.push(T);
    --num;
    while (num)
    {
        Tree *p = Q.front();
        Q.pop();
        p->lchild = new Tree();
        --num;
        Q.push(p->lchild);
        if (!num)
            break;
        p->rchild = new Tree();
        --num;
        Q.push(p->rchild);
    }
    
}

void input(Tree *T) {
    if (!T)
        return ;
    input(T->lchild);
    input(T->rchild);
    int x;
    cin >> x;
    T->data = x;
}

void print(Tree *T) {
    queue<Tree*> Q;
    Q.push(T);
    static bool leap = 1;
    while (!Q.empty())
    {
        Tree *p = Q.front();
        if (leap)
        {
            cout << p->data;
            leap = 0;
        }
        else
            cout << ' ' << p->data;
        Q.pop();
        if (p->lchild)
            Q.push(p->lchild);
        if (p->rchild)
            Q.push(p->rchild);
    }
}

int main() {
    Tree *T;
    int num;
    cin >> num;
    creat(T, num);
    input(T);
    print(T);
    return 0;
}