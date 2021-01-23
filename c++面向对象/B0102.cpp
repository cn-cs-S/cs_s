#include <iostream>

struct Student
{
    int num;
    float score;
    struct Student *next;
};

struct Student *creat() {
    Student *head = new Student;
    while (1)
    {
        Student *node = new Student;
        node->next = head->next;
        head->next = node;
        std::cin >> node->num >> node->score;
        if (!node->num)
            break;
    }
    return head;
}

void print(struct Student * head) {
    Student *h = head->next;
    if (!h->num)
    {
        std::cout << "Empty!";
        return ;
    }
    std::cout << "Score are:" << std::endl;
    while (!h->num)
    {
        std::printf("num:%d,score:%.2f\n", h->num, h->score);
        h = h->next;
    }
    return ;
}

int main()
{
    struct Student *creat();
    void print(struct Student * head);

    struct Student *pt;
    pt = creat();
    print(pt);

    return 0;
}