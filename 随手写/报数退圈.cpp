#include <iostream>
using namespace std;

//和c语言不同, 在使用struct类型定义变量时
//不需要写成struct xxx, 可直接写成xxx(c++推荐方式)
struct LNode    //定义链表
{
    int id;
    LNode *next;
};
//using c++11新特性, 用来起别名 (typedef)
//习惯上用LinkList表示头结点, LNode*表示普通结点
using LinkList = LNode *;
LinkList creat(int num)     //创建链表
{
    //new在堆中直接开辟内存, 和malloc作用类似
    /*注意点:
        1. new是运算符, malloc是函数
        2. new分配失败会抛出异常, malloc会返回NULL
        3. new开辟数组方式 : new type[size]
        4. new可以直接初始化开辟的内存, 在后面加个括号即可
           (如果开辟的不是基本类型会调用类的默认构造函数)
    */
    LinkList head = new LNode;
    head->id = 1;

    //因为后面用的是头插法, 所以直接让head->next指向自己
    head->next = head; 

    //此处采用的是头插法
    /*方法为:
        1. 首先判断是不是空链表
        2. 创建新结点
        3. 将新结点插入在头结点的后面
        ^_^简单吧 
        有此可见, 插入顺序和实际链表顺序相反
        所以这里数据倒着输入
    */
    for (int i = num; i > 1; --i) 
    {
        LNode *p = new LNode;
        p->id = i;  
        p->next = head->next;
        head->next = p;
    }

    return head;
}

//这个函数有两种写法, 只需稍微改动, 这个函数就可以变的很蠢
int circle(LinkList head) //退圈操作
{
    //循环链表如果只有一个元素, next会指向自己
    //所以这里的循环条件就是是否指向自己
    while (head && head != head->next)
    {
        //实现方法有待商榷, 看起来复杂但是实际上比判断3的倍数要快(大概)
        LNode *temp = head->next->next;
        head->next->next = head->next->next->next;
        //delete释放开辟的内存, 和free类似
        /*注意点:
            1. delete是运算符, free是函数
            2. 如果用new分配. 用delete释放
               如果是malloc分配, 用free释放, 要相互对应
            3. 如果delete用于释放数组, 要写成delete [] xx的形式
            4. 不要连续多次delete同一个指针
            5. "可能"的好习惯 delete后将指针置空
        */
        delete temp;
        //nullptr c++11新特性, 等同于NULL
        temp = nullptr;
        head = head->next->next;
    }
    return head->id;
}

int main()
{
    LinkList L = creat(100);

    cout << circle(L) << endl;

    //circle(L, 3);
    //cout << L->id << endl;

    return 0;
}