//main.cpp
#include"linklist.h"
int main()
{
	char x;
	char arr1 = 'm';
	char arr2 = 'n';
//在main函数中测试这些操作：
//初始化InitList(&L)；
	LinkList L;
	InitList(L);
	cout << "前插法:" << "*************" << endl;
//创建链表头插CreateList_H(&L)
	CreateList_H(L, 5);
//遍历ListTraverse(L);
	ListTraverse(L);
//取值GetElem(L, i, &e)、查找LocateElem(L, e)
	GetElem(L, 3,x);
	cout<<"所查找的值的地址为:"<<LocateElem(L,arr1)<<endl;
//插入ListInsert(&L, i, e)、删除ListDelete(&L, i);
	ListInsert(L, 2, arr2);
	ListTraverse(L);
	ListDelete(L,3);
	ListTraverse(L); 
//LinkList  Find(L, e) 、LinkList  Locate(L, i)
	cout<<"所查找值的位置为:"<<Find(L, arr1)<<endl;
	cout << "第i个值的地址为:" << Locate(L, 3) << endl;
//判空ListEmpty(L)、求表长ListLength(L)、释放DestroyList(&L)、置空ClearList(&L)；
	ListLength(L);
	ClearList(L);
	DestroyList(L);
	ListEmpty(L);

	cout << "尾插法:" << "*******************" << endl;
    //尾插CreateList_R(&L)
	CreateList_R(L);
	//遍历ListTraverse(L);
	ListTraverse(L);
	//取值GetElem(L, i, &e)、查找LocateElem(L, e)
	GetElem(L, 3, x);
	cout << "所查找的值的地址为:" << LocateElem(L, arr1) << endl;
	//插入ListInsert(&L, i, e)、删除ListDelete(&L, i);
	ListInsert(L, 2, arr2);
	ListTraverse(L);
	ListDelete(L, 3);
	ListTraverse(L);
	//LinkList  Find(L, e) 、LinkList  Locate(L, i)
	cout << "所查找值的位置为:" << Find(L, arr1) << endl;
	cout << "第i个值的地址为:" << Locate(L, 3) << endl;
	//判空ListEmpty(L)、求表长ListLength(L)、释放DestroyList(&L)、置空ClearList(&L)；
	ListLength(L);
	ClearList(L);
	DestroyList(L);
	ListEmpty(L);
}