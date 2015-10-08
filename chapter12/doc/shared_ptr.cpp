/******************

【make_shared函数】：在动态内存中分配一个对象并初始化它
初始化：
	·类似顺序容器的 emplace 成员，make_shared用其参数来构造给定类型的对象
	·如make_shared<string>时传递的参数必须与string的某个构造函数相匹配
	·如果不传递任何参数，对象会进行值初始化


******************/

#include <iostream>
#include <memory>
#include <string>
using namespace std;

void test1()
{
	shared_ptr<int> p1 = make_shared<int>(42);
	shared_ptr<string> p2 = make_shared<string>(10, '9');
	shared_ptr<int> p3 = make_shared<int>();
}

int main()
{

	return 0;
}

