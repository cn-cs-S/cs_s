#include <stdio.h>
#include <stdlib.h>

typedef struct players //定义结构体
{
    char name[30];
    char faculty[30];
    char song[60];
    double point[12];
    double aver;
    struct players *next;
} player;

player *creat(int n) // 创建链表
{
    player *head, *node, *end;
    head = (player *)calloc(1, sizeof(player));
    end = head;
    for (int i = 0; i < n; i++)
    {
        node = (player *)calloc(1, sizeof(player));
        scanf("%s%s%s", node->name, node->faculty, node->song); //输入基本信息
        end->next = node;
        end = node;
    }
    end->next = NULL;
    return head;
}

void people(player *x) //选手的分数
{
    static int i = 1; //第几个选手
    double max, min;

    printf("现在有请%d号选手上场，来自%s学院的%s，他的参赛歌曲为《%s》。\n", i, &x->faculty, &x->name, &x->song);

    getchar(); //交互
    getchar();

    printf("%d号选手比赛完毕，请各位评委开始打分。\n", i);

    for (int i = 0; i < 12; i++)
    {
        scanf("%lf", &x->point[i]);
    }

    max = x->point[0];
    min = x->point[0];

    printf("请各位评委亮分\n");

    for (int i = 0; i < 12; i++)
    {
        if (max < x->point[i])
        {
            max = x->point[i];
        }

        if (min > x->point[i])
        {
            min = x->point[i];
        }

        x->aver += x->point[i];

        printf("%5.1lf", x->point[i]);
    }
    x->aver = (x->aver - max - min) / 10;

    printf("\n");
    printf("去掉一个最高分%3.1lf，去掉一个最低分%3.1lf,%d号选手的最终分数为%4.2lf。\n\n", max, min, i++, x->aver);
    return;
}

void Bubble(player *head) //排序
{
    player *pre, *cur, *next, *end;
    end = NULL;
    while (head->next != end)
    {
        for (pre = head, cur = pre->next, next = cur->next; next != end; pre = pre->next, cur = cur->next, next = next->next)
        {
            if (cur->aver < next->aver)
            {
                pre->next = next;
                cur->next = next->next;
                next->next = cur;

                player *temp = cur;
                cur = next;
                next = temp;
            }
        }
        end = cur;
    }
    return;
}

void result(player *y) //比赛结果
{
    static int t = 1; //第几个选手
    getchar();        //交互
    printf("第%d名，来自%s的%s，他演唱的歌曲为《%s》，最后得分为%3.1lf。\n", t++, y->faculty, y->name, y->song, y->aver);
    return;
}

void songmatch(void) //歌手比赛函数
{
    int num;
    scanf("%d", &num);
    player *head = creat(num); //调用创建链表函数
    player *h = head;

    while (h->next != NULL)
    {
        h = h->next;
        people(h); //调用选手分数函数
    }

    h = head;

    Bubble(h); //调用排序函数

    getchar(); //交互
    getchar();

    printf("我宣布，本次大赛最后的成绩为\n");
    for (int i = 0; i < 3; i++)
    {
        h = h->next;
        result(h); //调用结果函数
    }

    return;
}

int main() //简洁的main函数
{
    songmatch();
    return 0;
}
