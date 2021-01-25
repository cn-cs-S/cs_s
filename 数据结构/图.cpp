/**
 * 此为图的各种操作
 * 仅供本人参考使用
 * 语言为c/c++
 * 注释比代码长系列
*/
//~图的算法略难啊啊啊啊

#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

using typec = char;
using typei = int;
const int MAX = 100;

//^邻接矩阵(数组)
/**
 * 用数组存点的信息
 * 用二维数组的下标记录两个点之间的关系
 * 网(有权图)另加一个成员储存权的信息
 * 
 * 1. 无向图的邻接矩阵对称
 * 2. 稀疏图空间效率低
 * 3. 查询边的数量速度慢
*/
struct AMGraph {
    typec vexs[MAX];
    typei arcs[MAX][MAX];
    int vexnum;
    int arcnum;
};

//无向网创建 邻接矩阵, 看一遍即可
void CreateUDN(AMGraph &G) {
    cin >> G.vexnum >> G.arcnum;//输入顶点数和边的数量
    for (int i = 0; i != G.vexnum; ++i)//输入顶点信息
        cin >> G.vexs[i];
    //这里可根据需求初始化, 推荐用fill函数, 头文件algorithm
    for (int i = 0; i != G.arcnum; ++i)//输入边的信息
    {
        typec v1, v2;
        typei w;
        cin >> v1 >> v2 >> w;
        G.arcs[v1][v2] = w;//这里默认边的信息为数组下标
        G.arcs[v2][v1] = G.arcs[v1][v2];
    }
}

//^邻接表(链表)
/**
 * 顶点用数组进行储存(头结点)
 * 边用链表进行储存(表结点)
 * 就是梦想中的储存方式, 每条都是链表
 * 
 * 1. 链表中元素顺序可变, 也就是邻接表不唯一
 * 2. 适合存储稀疏图
 * 3. 有向图的邻接表可存出度或入度(逆邻接表)
*/
//头结点定义
struct VexNode {
    typec data; //顶点信息
    ArcNode *firstarc;//指向第一个表结点
};
using AdjList = VexNode[MAX];

//表结点定义
struct ArcNode {
    int adjvex; //所指向的顶点位置
    ArcNode *nextarc;//指向下一个表结点
    typei info; //边相关信息
};

//图定义
struct ALGragh {
    AdjList vex;  //相当于VexNode vex[MAX]
    int vexnum;   //顶点数
    int arcnum;   //边数
};

//有向网的建立
void CreateUDG(ALGragh &G) {
    cin >> G.vexnum >> G.arcnum;
    for (int i = 0; i < G.vexnum; ++i)
    {
        cin >> G.vex[i].data;   //输入顶点信息
        G.vex[i].firstarc = nullptr;//将指针域置空
    }
    for (int i = 0; i < G.arcnum; i++)
    {
        typec v1, v2;
        ArcNode *p = new ArcNode;
        p->adjvex = v2; 
        //头插法
        p->nextarc = G.vex[v1].firstarc;
        G.vex[v1].firstarc = p;
    }
}

//^十字链表
/**
 * 十字链表即邻接表和逆邻接表的结合
 * 用于有向图
 * 用于解决统计顶点的度
 * 头结点增加一个指针域指向入度边
 * 表结点增加一个数据域, 用于说明边的指向
 * 如 : 0 2 即为0指向2; 2 0 即为2指向0
*/

//^邻接多重表 (看起来太麻烦不给实现, 而且不实用感觉)
/**
 * 用于无向图
 * 解决无向图每条边储存两遍的问题
*/

//^图的遍历 一通全通~递归永远的神
/**
 * 每个顶点只遍历一次
 * 为此我们需要一个标志数组记录是否访问过
 * 以下是常用遍历方式 (概率更新)
*/

//深度优先搜索(DFS)
/**
 * 递归 栈辅助(系统栈也是栈^_^)
 * 一条路走到黑
 * 遇到没访问过的顶点就入栈, 再看下一个, 没路就弹出返回
 * 类似于二叉树的先序遍历
*/

//邻接矩阵DFS
void DFS(AMGraph G, int v) {
    bool visited[MAX];
    //数组元素初始化
    fill(visited, visited+G.vexnum, 0);
    cout << v << endl;
    visited[v] = true;
    //递归遍历
    for (int i = 0; i < G.vexnum; ++i)
        if (G.arcs[v][i] && !visited[i])//如果有边并且没访问过
            DFS(G, i);      //递归遍历下一个点
}

//邻接表DFS(未写)
void DFS(ALGragh G, int v) {
    
}

//广度优先搜索(BFS)
/**
 * 非递归 队列辅助
 * 广撒网, 将遇到的顶点相邻的没访问的结点入队
 * 弹出
 * 类似于二叉树的层次遍历
*/

//邻接表BFS
void BFS(ALGragh G, int v) {
    queue<VexNode> Q;
    bool visited[MAX];
    fill(visited, visited+G.vexnum, 0);
    Q.push(G.vex[v]);
    cout << G.vex[v].data << endl;
    while (!Q.empty())
    {
        ArcNode *w = Q.front().firstarc;
        while (w)
        {
            Q.push(G.vex[w->adjvex]);
            cout << G.vex[w->adjvex].data << endl;
            visited[w->adjvex] = 1;
            w = w->nextarc;
        }
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
