#include"linklist.h"
int n;
status InitList(LinkList& L)//初始化单链表
{
	L = new LNode;//开辟内存空间，创建头结点
	L->next = NULL;//头结点的指针域为空
	return OK;
}
void CreateList_H(LinkList& L, int n)//创建单链表(头插)
{
	InitList(L);
	for (int i = 0; i < n; i++)
	{
		LNode* s = new LNode;//创建结点
		cin >> s->data;//在数据域输入数据
		s->next = L->next;
		L->next = s;
	}
}
void CreateList_R(LinkList& L)//单链表创建(尾插)
{
	L = new LNode;
	L->next = NULL;
	LNode* r;//创建尾指针
	r= L;//尾指针指向头结点
	for (int i = 0; i < n; ++i)
	{
		LNode* p = new LNode;//创建新结点
		cin >> p->data;
		p->next = NULL;
		r->next = p;//尾结点就是当前单链表最后面的结点
		r = p;//将尾指针指向末尾的结点
	}
}
status ListTraverse(LinkList L)//遍历单链表***
{
	LNode* p = L->next;
	while (p)
	{
		p = p->next;
		cout << p->data << " ";
	}
	return OK;
}
status GetElem(LinkList L, int i, ElemType& e)//取值(平均时间复杂度为o(n)
{
	LNode* p;//p指针可以指向任意结点
	p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;
	e = p->data;//取第i个结点的值域
	cout << "所取的值为:" << e << endl;
	return OK;
}
LNode* LocateElem(LinkList& L, ElemType e)//查找(时间复杂度o(n)
{
	LNode* p;
	p=L->next;//首元结点
	while (p && p->data != e)
		p = p->next;
	return p;//返回所查e的地址
}
status ListInsert(LinkList& L, int i, ElemType e)//插入(时间复杂度o(n)
{//在单链表第i个位置插入值为e的新结点
	LNode* p;
	p = L;
	int j = 0;
	while (p && (j < i - 1))
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
		return ERROR;
	LNode* s = new LNode;//生成新结点*s
	s -> data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
status ListDelete(LinkList& L, int i)//删除(时间复杂度o(n)
{//删除第i个元素
	LNode* p = L;
	int j = 0;
	while((p->next) && (j<i - 1))
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || (j > i - 1))
		return ERROR;
	LNode* q;
	q = p->next;//临时保存被删结点的地址以备释放
	p->next = p->next->next;//p->next=q->next;
	delete q;
	return OK;
}
status ListEmpty(LinkList L)//判空
{
	LNode* p=L;
	if (p->next == NULL)
		cout << "单链表为空链表" << endl;
	return OK;
}
status ListLength(LinkList L)//求表长
{
	LNode* p = L;
	int j = 0;
	while (p)
	{
		p = p->next;
		++j;
	}
	cout << "表长为:" << j << endl;
	return OK;
}
status DestroyList(LinkList& L)//释放
{
	LNode* p = L;
	while(p!=NULL)
	{
		p = p->next;
		delete p;
	}
	L = NULL;
	return OK;
}
status ClearList(LinkList& L)//置空
{
	LNode* p = L;
	while (p!=NULL)
	{
		p = p->next;
		p = NULL;
	}
	L->next = NULL;
	return OK;
}
LinkList  Find(LinkList L, char e)//查找所找值所在结点的内存地址
{
	LNode* p = L->next;
	while (p && p->data != e)
	{
		p = p->next;
	}
	return p;
}
LinkList  Locate(LinkList L, int i)//按位查找
{
	LNode* p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}


