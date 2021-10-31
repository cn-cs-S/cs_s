#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct PNode
{
    float coef;         //系数
    int expn;           //指数
    struct PNode *next; //指针域
} PNode, *Polynomial;

void show(Polynomial &p)
{
    if (!p)
    {
        cout << "Empty!" << '\n';
        return;
    }

    Polynomial t = p;
    while (t = t->next)
    {
        if (!t->coef)
            continue;
        if (t == p->next)
            cout << "f(x)=";
        else
            cout << '+';
        if (t->coef == 1 && !t->expn)
            ;
        else
            cout << t->coef;
        if (t->coef && t->coef != 1 && t->expn)
            cout << '*';
        if (t->expn == 1)
            cout << 'x';
        if (t->expn != 0 && t->expn != 1)
            cout << "x^" << t->expn;
    }
    cout << '\n';
}

int cmp(Polynomial a, Polynomial b)
{
    return a->coef < b->coef;
}

void CreatePolyn(Polynomial &p, int num)
{
    p = new PNode;
    p->next = NULL;
    vector<Polynomial> v;
    for (int i = 0; i < num; i++)
    {
        Polynomial t = new PNode;
        cin >> t->coef >> t->expn;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cmp);
    for (vector<Polynomial>::iterator i = v.begin(); i != v.end(); ++i)
    {
        (*i)->next = p->next;
        p->next = *i;
    }
}

int main()
{
    Polynomial pa = NULL, pb = NULL;
    show(pa);
    CreatePolyn(pa, 3);
    show(pa);
    CreatePolyn(pb, 4);
    show(pb);
    return 0;
}