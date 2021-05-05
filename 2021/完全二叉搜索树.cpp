#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct Tree{
    Tree *left;
    Tree *right;
    int num;
    Tree(): left(nullptr), right(nullptr){}
};

void assert(Tree *&tree, int num){
    
    if (num > tree->num) {
        if (!tree->left) {
            auto t = new Tree;
            t->num = num;
            tree->left = t;
            return ;
        }
            
        assert(tree->left, num);
    }

    else {
        if (!tree->right) {
            auto t = new Tree;
            t->num = num;
            tree->right = t;
            return ;
        }

        assert(tree->right, num);
    }
}

int main() {
    Tree* t = new Tree;
    int n;
    cin >> n;
    int x;
    cin >> x;
    t->num = x;
    
    for (int i = 0; i < n-1; i++)
    {
        int x;
        cin >> x;
        assert(t, x);
    }

    bool first = true;
    queue<Tree*> q;
    vector<Tree*> v;
    q.push(t);
    v.push_back(t);
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
        v.push_back(temp->left);
        v.push_back(temp->right);
        if (first) {
            cout << temp->num;
            first = false;
        }
        else
            cout << ' ' << temp->num;
    }
    cout << endl;
    bool leap = 1;
    for (int i = 0; i < n; i++)
    {
        if (!v[i])
        {
            leap = 0;
            break;
        }
    }
    if (leap)
        cout << "YES";
    else
        cout << "NO";
}