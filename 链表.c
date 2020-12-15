#include<stdio.h>
#include<stdlib.h>
typedef struct student  //定义结构体，包含数据域和指针域
{
    int score;          //数据域
    struct student *next;//指针域
    
}LinkList;

LinkList *creat(int n)  //创建链表函数
{
    LinkList *head,*node,*end;//定义头指针，子指针，尾指针
    head=(LinkList*)malloc(sizeof(LinkList));//为头指针分配空间
    end=head;                   //若为空，则头尾相等
    //过程中，可认为end指针偏移，而不只是尾指针
    for (int i = 0; i < n; i++) //输入链表
    {
        node = (LinkList*)malloc(sizeof(LinkList));//为子指针分配空间，注：node为指针类型
        scanf("%d",&node->score);   //输入子指针的数据
        end->next=node;         //令前一个指针的指针指向子指针
        end=node;               //令指针指向当前指针
    }
    end->next=NULL;             //尾指针的指针域赋空
    return head;                //返回头指针，注：返回值为指针类型
}

int main()
{
    int m=3;
    LinkList *head=creat(m);//遍历链表
    while (head->next!=NULL)
    {
        head=head->next;
        printf("%3d",head->score);
    }
    return 0;
    
    
}