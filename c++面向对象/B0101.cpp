#include<iostream>

struct Student {
    int num;
    float score;
    Student *next;
};

int main(){
    Student a, b, c, *head, *p;
    a.num = 10101; a.score = 89.5;
    b.num = 10103; b.score = 90;
    c.num = 10107; c.score = 85;

    head = &a;
    a.next = &b;
    b.next = &c;
    c.next = NULL;

    p = head;
    while (p)
    {
        std::cout << p->num << ',' << p->score << std::endl;
        p = p->next;
    }
    
    return 0;
}