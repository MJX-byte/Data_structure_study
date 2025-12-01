#include"tree_study.h"
int main()
{
	int x;
	Bitree T = NULL;
	Bitree p, pr;
	fin.open("input.txt");
	{
		if (!fin)
			cout << "文件未成功打开!";
	}

	while (fin >> x)
	{
		insert(T, x);
	}
	fin.close();
	cout << "先序遍历结果为:";
	Inordertraverse(T);
	cout << endl;
	cout << "中序遍历结果为:";
	Mordertraverse(T);
	cout << endl;
	cout << "后序遍历结果为:";
	Fordertraverse(T);
	cout << endl;
	cout << "树的高度为:" << TreeHeight(T)<<endl;
	cout << "结点数:" << NodeCount(T)<<endl;
	cout << "叶子结点数:" << LeafCount(T)<<endl;
	cout << "非叶子结点数:" << NonLeafCount(T)<<endl;
	int m = 10;
	find(T, m, p, pr);
	if (p == NULL)
		cout << "false";
	else
		cout << "true";
	return 0;
}