#include <stdio.h>
#include <stdlib.h>
//*注，用calloc,不用malloc,血的教训
//*有序双向链表
/*
*单向链表暂时不知道怎么搞qwq
*感觉自己的方法思路对但是过程麻烦了
*运用牛逼的百度的时候到了(还有google)
*链表不好操作啊^_^
*以下均有注释(注释比代码长系列)
*/
typedef struct student //&创建结构体
{
    int score;
    struct student *pre;
    struct student *next;
} LinkList;

LinkList *creat(int n) //&创建链表函数
{
    LinkList *head, *node, *end;                    //定义头指针，子指针，尾指针
    head = (LinkList *)calloc(1, sizeof(LinkList)); //为头指针分配空间
    end = head;                                     //若为空，则头尾相等
    for (int i = 0; i < n; i++)                     //输入链表
    {
        node = (LinkList *)calloc(1, sizeof(LinkList)); //为子指针分配空间，注：node为指针类型
        scanf("%d", &node->score);                      //输入子指针的数据
        LinkList *h = head;                             //!有序链表核心，遍历链表，插入元素
        int leap = 1;                                   //标志变量(或许不需要？)
        while (h->next != NULL)                         //^这个判断可以判断是不是空链表
        {
            h = h->next;                //遍历
            if (node->score < h->score) //^若满足条件就插入元素
            {                           //^以下看不懂自行画图
                node->pre = h->pre;     //接pre指针
                h->pre->next = node;    //接next指针
                h->pre = node;          //接pre指针
                node->next = h;         //接next指针
                leap = 0;
                break; //^这里不需要后移尾指针
            }
        }
        if (leap) //^若没操作则插入链表的最后面
        {
            node->pre = end;  //接pre指针
            end->next = node; //接next指针
            end = node;       //尾指针后移
        }
    }
    end->next = NULL; //尾指针的指针域赋空
    return head;      //返回头指针，注：返回值为指针类型
}

int main()
{
    int m = 5;
    LinkList *head = creat(m); //遍历链表
    while (head->next != NULL)
    {
        head = head->next;
        printf("%3d", head->score);
    }
    return 0;
}