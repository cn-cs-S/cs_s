/**
 * 此为树的各种操作
 * 仅供本人参考使用
 * 语言为c/c++
 * 注释比代码长系列
 * 未调试, 或许会有错误, 仅为学习过程笔记
*/
//~ 二叉树(binary tree)略难啊 要被虐哭了qwq
//~ 二叉树简直是数据结构的精髓

#include<iostream>
#include<stack>
#include<queue>
using namespace std;
/**
 * 二叉树的性质  p.s. 理论知识知道即可
 * 
 * 1. 第i层至多有 pow(2, i-1) 个结点
 * 2. 深度为k的二叉树至多有 pow(2, k)-1 个结点
 * 3. 叶子数 = 度为2的结点数 + 1
 * 
 * 特殊的二叉树 : 满二叉树, 完全二叉树
 * 满二叉树 :
 *     ^深度为k, 且有pow(2, k)-1个结点; 直观来看叶子全在最底层且满
 * 完全二叉树:
 *     ^在满二叉树的基础上从右边缺少叶子; 直观来看叶子全在底层, 从左到右排列
 *     ^具有n个结点的完全二叉树的深度为 |log(n)| + 1
 */

//顺序存储法不做笔记啦~用的少而且简单, 重点放在链式存储
//顺序存储法适合满二叉树和完全二叉树, 其他一律链式

//抽象类型定义
using type = char; //类型自定义
struct BiNode {
    type data;
    BiNode *lchild;
    BiNode *rchild;
    //BiNode *parent; 三叉链表
};
using BiTree = BiNode*;

//建立
void CreateBiTree(BiTree &T/*, definition*/) {

}

//访问函数, 自定义操作
void visit(BiTree T) {

}

//遍历的递归算法, 可看出先中后的区别只有顺序的区别
//先序遍历
void PreOrderTraverse(BiTree T) {
    if (!T) 
        return ;
    visit(T);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}
//中序遍历
void InOrderTraverse(BiTree T) {
    if (!T)
        return ;
    InOrderTraverse(T->lchild);
    visit(T);
    InOrderTraverse(T->rchild);
}
//后序遍历
void PostOrderTraverse(BiTree T) {
    if (!T)
        return ;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    visit(T);
}

//遍历的非递归算法, 用栈辅助操作
//中序遍历
void InOrderTraverse(BiTree T) {
    stack<BiNode*> S;
    BiTree p = T;
    while (p || !S.empty())
    {
        if (p)
        {
            S.push(p);
            p = p->lchild;
        }
        else
        {
            BiNode *q = S.top();
            S.pop();
            visit(q);
            p = q->rchild;
        }
    }
}

//层次遍历, 用队列辅助操作
void LevelOrder(BiTree T) {
    queue<BiNode*> Q;   //创建队列
    Q.push(T);          //将根结点入队
    while (!Q.empty())  //如果队列不为空
    {
        BiNode *p = Q.front();//记录待出队结点
        Q.pop();            //出队
        visit(p);           //访问
        if (p->lchild)      //如果有左结点将左结点入队
            Q.push(p->lchild);
        if (p->rchild)      //如果有右结点将右结点入队
            Q.push(p->rchild);
    }
}

//先根建立二叉树
void CreateBiTree(BiTree &T) {
    type ch;
    cin >> ch;
    if (ch == '$')  //标志空子树
        T = nullptr;
    else
    {
        T = new BiNode;
        T->data = ch;
        CreateBiTree(T->lchild);//递归建立左子树
        CreateBiTree(T->rchild);//递归建立右子树
    }
}

//复制二叉树, 同遍历, 采用递归的思想
void CopyBiTree(BiTree T, BiTree &B) {
    if (!T)
    {
        B = nullptr;
        return ;
    }
    else
    {
        B = new BiNode;
        B->data = T->data;
        CopyBiTree(T->lchild, B->lchild);
        CopyBiTree(T->rchild, B->rchild);
    }
}

//计算二叉树深度, 递归思想
int DepthBiTree(BiTree T) {
    if (!T)
        return 0;
    int m = DepthBiTree(T->lchild); //递归计算左子树深度
    int n = DepthBiTree(T->rchild); //递归计算右子树深度
    return m > n ? m+1 : n+1;   //左右子树大的那个加1
}

//计算二叉树结点个数, 递归
int NodeCount(BiTree T) {
    if (!T)
        return 0;
    //左右子树和+1
    return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}

//计算二叉树叶子结点个数, 递归
int LeavesCount(BiTree T) {
    if (!T)
        return 0;
    if (!T->lchild && !T->rchild)
        return 1;
    return LeavesCount(T->lchild) + LeavesCount(T->rchild);
}


//线索二叉树此处只给定义不给实现
//线索二叉树是用空子树存储前驱后继的特殊二叉树
//常见如, 左空子树存前驱, 右空子树存后继等
//具体应用自行掌握

int main(int argc, char const *argv[])
{
    
    return 0;
}
