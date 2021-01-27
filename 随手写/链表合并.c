#include<stdio.h>
#include<stdlib.h>

typedef struct Student
{
    int num;
    double score;
    struct Student* next;
}Student;

Student* creat()
{
    Student *head, *node, *end;
    head = (Student*)calloc(1, sizeof(Student));
    end = head;
    do
    {
        node = (Student*)malloc(sizeof(Student));
        scanf("%d,%lf", &node->num, &node->score );
        end->next = node;
        end = end->next;
        end->next = NULL;
    } while (end->num);
    return head;
}

Student* creatSortedList()
{
    Student *head, *node, *end;
    head = (Student*)calloc(1, sizeof(Student));
    end = head;
    
    do
    {
        Student *h = head;
        int leap = 1;
        node = (Student*)malloc(sizeof(Student));
        scanf("%d,%lf", &node->num, &node->score);
        if (node->num)
        {
            while (h->next)
            {
                if (node->num <= h->next->num)
                {
                    leap = 0;
                    break;
                }
                h = h->next;
            }
        }
        if (leap)
        {
            end->next = node;
            end = end->next;
        }
        else
        {
            node->next = h->next;
            h->next = node;
        }
    } while (end->num);
    return head;
}

void print(Student *head)
{
    Student *h = head->next;
    if (!h->num)
    {
        printf("Empty!\n");
        return ;
    }
    printf("Scores are:\n");
    while (h->next && h->num)
    {
        printf("num:%d,score:%.2lf\n", h->num, h->score);
        h = h->next;
    }
}

Student* combine(Student* p1, Student* p2)
{
    Student *p;
    p2 = p2->next;
    while (p2->num)
    {
        p = p1;
        Student *q = p2;
        while (q->num >= p->next->num && p->next->num)
        {
            p = p->next;
        }
        q->next = p->next;
        p->next = q;
        p2 = p2->next;
    }
    return p1;
}

int main(int argc, char const *argv[])
{
    Student *pt1, *pt2;
    printf("Sorted List:\n");
    pt1 = creatSortedList();
    print(pt1);

    printf("\nList:\n");
    pt2 = creat();
    print(pt2);

    printf("\nCombining...\n");
    pt1 = combine(pt1, pt2);
    print(pt1);
    return 0;
}
