#pragma once
#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define MAXSIZE 100
typedef char ElemType;
typedef char status;
typedef struct LNode//单链表结构声明 
{
	ElemType  data;//值域
	struct LNode* next;//指针域
}LNode, * LinkList;
//初始化单链表***
status InitList(LinkList& L);
//创建单链表头插***
void CreateList_H(LinkList& L, int n);
//创建链表尾插CreateList_R(&L)***
void CreateList_R(LinkList& L);
//遍历ListTraverse(L)******
status ListTraverse(LinkList L);
//取值GetElem(L,i,&e)***
status GetElem(LinkList L, int i,char &e);
// 查找LocateElem(L, e)***
LNode* LocateElem(LinkList L, char e);
//插入ListInsert(&L, i, e)***
status ListInsert(LinkList& L, int i, char e);
// 删除ListDelete(&L, i, &e)***
status ListDelete(LinkList& L, int i);
//判空ListEmpty(L)******
status ListEmpty(LinkList L);
// 求表长ListLength(L)******
status ListLength(LinkList L);
//释放DestroyList(&L)******
status DestroyList(LinkList& L);
// 置空ClearList(&L)；******
status ClearList(LinkList& L);
//弱化位序后的按值和按位查找（返回指针）： 
LinkList  Find(LinkList L, char e);

LinkList  Locate(LinkList L, int i);