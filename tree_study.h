#pragma once
#include<iostream>
#include<fstream>
using namespace std;
extern ifstream fin;
#define ERROR 0
#define OK 1
typedef int status;
typedef int telemtype;
typedef struct BiTNode {
	telemtype data;
	struct BiTNode* lchild, * rchild;//定义左右孩子指针
}BiTNode,*Bitree;
//栈结构体
typedef struct LNode {
	Bitree data;
	struct LNode* next;
}LNode, *Linkstack;


/*1. 使用补虚结点先序序列创建二叉树的算法构造一棵二叉树。
================遍历==================
2.实现二叉树递归遍历算法，给出这棵二叉树的先序、中序、后序序列。
3.实现二叉树先序、中序遍历的非递归算法，测试之。
4.实现二叉树的层次遍历算法：
============== = 算法设计================
5.设计算法，给出该树的高度 / 结点总数 / 叶子结点数 / 非叶子结点数。
6.设计算法，找到位于二叉树先序序列中第2个位置的结点的值，如果有存为x。
7.删除并释放二叉树中以元素值为x的结点作为根的子树。
8.释放二叉树的所有结点空间*/

//增广先序序列创建二叉树
void createBitree(Bitree& T);
//先序遍历
void Inordertraverse(Bitree T);
//中序遍历
void Mordertraverse(Bitree T);
//后序遍历
void Fordertraverse(Bitree T);
void initstack(Linkstack& S);
status push_stack(Linkstack& S, Bitree e);
status pop_stack(Linkstack& S, Bitree& e);
status stackempty(Linkstack S);
void PreOrder(Bitree T);
void InOrder(Bitree T);
void PostOrder(Bitree T);
int TreeHeight(Bitree T);// 树的高度
int NodeCount(Bitree T);// 总节点数
int LeafCount(Bitree T);// 叶子节点数（度为0）
int NonLeafCount(Bitree T);// 非叶子节点数（度≥1）
status FindPreOrder2nd(Bitree T, telemtype& x);//查找先序序列中第2个节点
void DeleteSubtree(Bitree& T, telemtype x);//删除以x为根的子树（释放空间）
status DestroyBitree(Bitree& T);//释放整棵二叉树的空间

//二叉排序树的查找算法(迭代)
void find(Bitree T, telemtype x, Bitree& p, Bitree& pr);
//二叉排序树的插入算法(非递归)
void insert(Bitree& T, telemtype x);

void createBst(Bitree& T, int a[], int n);//二叉排序树创建
