#include"linkstack.h"
int main()
{
	Linkstack M;
	int n;
	lselemtype e='\0';//初始化e，char类型
	initstack(M);
	std::cout << "请输入要入栈的字符数量:";
	std::cin >> n;
	std::cout << "请输入要入栈的字符:";
	for (int i = 0; i < n; i++)
	{
		std::cin >> e;
		push_stack(M, e);
	}
		
	Traverse(M);
	stackempty(M);//判断栈是否为空
	std::cout << "此时栈顶元素为:";
	std::cout << GetTop(M);
	pop_stack(M,e);//将栈顶元素移出栈
	std::cout << std::endl;
	std::cout << "栈顶元素移出后的链栈为:" <<std::endl;
	Traverse(M);
	Clearstack(M);
	Destroystack(M);
	return 0;
}