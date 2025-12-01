#include"tree_study.h"
ifstream fin;
//增广先序序列创建二叉树
void createBitree(Bitree& T)
{
	int ch;
	fin >> ch;
	if (ch == '-1')
		T = NULL;
	else
	{
		T = new BiTNode;
		T->data = ch;
		createBitree(T->lchild);//递归
		createBitree(T->rchild);
	}
}
//先序遍历
void Inordertraverse(Bitree T)
{
	if (T)
	{
		cout << T->data << " ";//打印根结点
		Inordertraverse(T->lchild);//左
		Inordertraverse(T->rchild);//右
	}
	//cout << endl;
}
//中序
void Mordertraverse(Bitree T)
{
	if (T)
	{
		Mordertraverse(T->lchild);
		cout << T->data << " ";
		Mordertraverse(T->rchild);
	}
	//cout << endl;
}
//后序
void Fordertraverse(Bitree T)
{
	if (T)
	{
		Fordertraverse(T->lchild);
		Fordertraverse(T->rchild);
		cout << T->data << " ";
	}
	//cout << endl;
}
void initstack(Linkstack& S)
{
	S = new LNode;
	S->next = NULL;
}
status push_stack(Linkstack& S, Bitree e)
{
	LNode* newnode = new LNode;
	newnode->data = e;
	newnode->next = S->next;
	S->next = newnode;
	return OK;
}
status pop_stack(Linkstack& S, Bitree& e)
{
	if (S->next == NULL)
	{
		return ERROR;
	}
	Linkstack p = S->next;
	e = p->data;
	S->next = p->next;
	delete p;
	return OK;
}
status stackempty(Linkstack S)
{
	return (S->next == NULL) ? OK : ERROR;
}
void PreOrder(Bitree T) {
		Linkstack S;   
		initstack(S);
		Bitree p = T; 
		//Bitree temp = NULL;
		//push_stack(S, temp);
	while (p != NULL||!stackempty(S)) {
			if (p != NULL) {
			cout <<p->data << " "; // 访问根节点
			push_stack(S, p);        // 根节点入栈（后续要访问右子树）
			p = p->lchild;          // 优先遍历左子树
		    }
		else {
			pop_stack(S, p);         // 左子树遍历完，出栈取根节点
			p = p->rchild;          // 遍历右子树
		}
	}
}
void InOrder(Bitree T)
{
	Linkstack S;
	initstack(S);
	Bitree p = T;//树指针指向树的根节点
	while (p != NULL || !stackempty(S))
	{
		if (p != NULL) {
			push_stack(S, p);//根结点入栈
			p = p->lchild;//遍历左子树
		}
		else {
			pop_stack(S, p);//左子树遍历完，出栈取根结点
			cout << p->data << " ";//访问根结点
			p = p->rchild;//遍历右子树
		}
	}
}
void PostOrder(Bitree T) {
	Linkstack S1, S2;//声明两个栈
	initstack(S1);
	initstack(S2);
	push_stack(S1, T);//根结点入栈1
	while (!stackempty(S1))
	{
		Bitree p;
		pop_stack(S1, p);//栈1出栈结点
		push_stack(S2, p);//压入栈2
		
		if (p->lchild)
		push_stack(S1, p->lchild);
		if (p->rchild)
			push_stack(S1, p->rchild);
	}
	//弹出栈2，即为后序遍历
	while (!stackempty(S2)) {
		Bitree p;
		pop_stack(S2, p);
		cout << p->data << " ";
	}
}
int TreeHeight(Bitree T)//树的高度
{
	if (!T) return 0;
	int left_h = TreeHeight(T->lchild);
	int right_h = TreeHeight(T->rchild);
	return (left_h > right_h ? left_h : right_h)+1;
}
int NodeCount(Bitree T)//总结点数
{
	if (!T) return 0;
	return 1 + NodeCount(T->lchild) + NodeCount(T->rchild);// 当前节点数 + 左子树节点数 + 右子树节点数
}
int LeafCount(Bitree T)//叶子节点数,度为0
{
	if (!T)return 0;
	if (!T->lchild && !T->rchild) {
		return 1;
	}
     return LeafCount(T->lchild) + LeafCount(T->rchild); // 递归统计左右子树
}
// 非叶子节点数（总节点数 - 叶子节点数）
int NonLeafCount(Bitree T)//非叶子节点数,度>=1
{
	return NodeCount(T) - LeafCount(T);
}
// 用静态变量计数（递归中保持计数状态）
static int preIdx = 0; // 先序遍历计数器
/*status FindPreOrder2nd(Bitree T, telemtype& x) {
	preIdx = 0; // 重置计数器（避免多次调用出错）
	// 辅助递归函数
	function<bool(Bitree)> dfs = [&](Bitree node) {
		if (!node) return false;
		preIdx++;
		if (preIdx == 2) { // 找到第2个节点
			x = node->data;
			return true;
		}
		// 先序遍历：左→右（找到后立即返回，剪枝）
		return dfs(node->lchild) || dfs(node->rchild);
		};
	return dfs(T) ? OK : ERROR; // 找不到返回ERROR（如树节点数<2）
}*/
void DeleteSubtree(Bitree& T, telemtype x) {
	if (!T) return;
	// 找到目标节点，释放其整个子树
	if (T->data == x) {
		DestroyBitree(T); // 调用释放整树函数
		T = NULL; // 置空，避免野指针
		return;
	}
	// 递归查找左右子树
	DeleteSubtree(T->lchild, x);
	DeleteSubtree(T->rchild, x);
}
status DestroyBitree(Bitree& T) {
	if (!T) return ERROR;
	// 后序遍历：先释放左右子树，再释放当前节点
	DestroyBitree(T->lchild);
	DestroyBitree(T->rchild);
	delete T; // 释放当前节点
	T = NULL; // 置空，避免野指针
	return OK;
}

//////////////////
void find(Bitree T, telemtype x, Bitree& p, Bitree& pr)//查找算法
{
	//在二叉排序树t 中查找关键字等于x 的结点
    //成功时p 返回找到结点地址, pr 是其双亲结点 
    //不成功时p 为空, pr 返回最后走到的结点地址
	    p = NULL;//从根查找
		pr = NULL;//初始化pr指针//初始化p，pr指针为空
		if (T == NULL)
		{
			return;
		}
		p = T;
		while (p != NULL && p->data != x)
		{
			pr = p;
			if (x > p->data)
				p = p->rchild;
			else
				p = p->lchild;
		}
	}

void insert(Bitree& T, telemtype x)//插入算法
{
	//将x插入以*T为根的树中
	BiTNode* pt, *prt = NULL, *q;//结点指针
	find(T, x, pt, prt);
	if (pt == NULL)
	{
		q = new BiTNode;//创建新结点
		q->data = x;
		q->lchild = q->rchild = NULL;
		if (prt == NULL)///prt返回的是最后走到的结点地址
			T = q;//空树
		else if (x < prt->data)
			prt->lchild = q;
		else
			prt->rchild = q;
	}
}

