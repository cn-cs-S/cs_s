#include<stdio.h>
#include<stdlib.h>
typedef struct stu
{
    int score;
    struct stu *pre,*next;
}stu;

stu *creat(int n)
{
    stu *head,*note,*end;
    head=(stu*)calloc(1,sizeof(stu));
    end=head;
    for (int i = 0; i < n; i++)
    {
        note=(stu*)calloc(1,sizeof(stu));
        end->next=note;
        note->pre=end;
        end=note;
    }
    end->next=NULL;
}