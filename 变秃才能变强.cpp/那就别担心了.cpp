#include<iostream>
using namespace std;

struct body{
    int data;
    body *next;
};

struct head{
    int head;
    body *next;
};

struct tu{
    head *_head;
};

int main(){
    int N, M;
    cin >> N >> M;
    tu mingti;
    mingti._head = new head[N];
    for (int i = 0; i < M; i++)
    {
        int x;
        body *y;
        cin >> x >> y->data;
        y->next = mingti._head[x-1].next;
        mingti._head[x-1].next = y;
    }
    int A, B;
    cin >> A >> B;
    int *visited = new int [N]();
    int sum = 0;
    int leap = 1;
    visited[A-1] = 1;
    
}