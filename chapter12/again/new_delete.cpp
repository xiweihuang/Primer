/*




*/

#include <iostream>
using namespace std;

void dynamic_allocate()
{
	int a;
	int b;
	
	// 默认初始化，内置类型或组合类型的对象的值是未定义的。而类类型的对象将用默认构造函数进行初始化
	int *p1 = new int;
	int *p2 = new int;

	string *ps = new string;  // 初始化为空的string
	int *pi = new int;  // pi指向一个未初始化的int
}

void init_var()
{
	// 1.直接初始化

	// 2.圆括号


	// 3.列表初始化


	// 4.值初始化
}

int main()
{
	dynamic_allocate();
	return 0;
}

