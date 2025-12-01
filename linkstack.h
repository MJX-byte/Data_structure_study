#pragma once
//实现一个char型的链栈栈，并完成其基本操作：
//IniStack，Push，Pop，GetTop，Traverse
//ClearStack，DestroyStack, StackEmpty
#include<iostream>
//using namespace std;
#define ERROR 0
#define OK 1
typedef char status;
typedef char lselemtype;
typedef struct LNode {
	lselemtype data;
	struct LNode* next;
}LNode,* Linkstack;
void initstack(Linkstack& S);//***
status push_stack(Linkstack& S, lselemtype& e);//
status pop_stack(Linkstack& S, lselemtype& e);//
lselemtype GetTop(Linkstack S);//
status Traverse(Linkstack S);//
status Clearstack(Linkstack& S);//
status Destroystack(Linkstack& S);//
bool stackempty(Linkstack& S);


