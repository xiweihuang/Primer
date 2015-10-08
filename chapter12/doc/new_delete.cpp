/*
【使用new动态分配和初始化对象】
	1.默认初始化
	2.直接初始化（圆括号、花括号）
	3.值初始化

【动态分配的const对象】
类似其他任何const对象，一个动态分配的const对象必须进行初始化。
但对于一个定义了默认构造函数的类类型，其const动态对象是可以隐式初始化的。
new const，返回的指针也是一个指向const的指针

【释放动态内存】
delete，与new相似，执行两个动作：
1.销毁给定的指针指向的对象
2.释放对应的内存

【指针值和delete】
传递给delete的指针需满足以下条件：
1.必须是动态分配的内存（局部变量的地址，是错误的）
2.可以是空指针（释放一个空指针总是没有错误的）
3.如果需要释放的内存已经被释放了，其行为是未定义的。即相同的指针值不能释放多次

【动态内存的管理容易出现的问题：】
1.内存泄露
2.使用已经释放掉的对象
3.同一块内存释放两次
建议：只使用智能指针

【delete之后重置指针值......】
delete  -->  变成空悬指针
避免方法，在指针即将要离开其作用域之前释放掉它所关联的内存
但~~~这也只是提供了有限的保护（参考reset_ptr()的代码）

*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

void dynamic_allocate()
{
	// 1.默认初始化，内置类型或组合类型的对象的值是未定义的。而类类型的对象将用默认构造函数进行初始化
	int *p1 = new int;
	int *p2 = new int;
	string *ps = new string;  // 初始化为空的string
	int *pi = new int;  // pi指向一个未初始化的int

	// 2.直接初始化
	// ①传统的构造方式（圆括号）
	// ②列表初始化（花括号）
	int *pd = new int(1024);
	string *pstr = new string(10, '9');
	vector<int> *pv = new vector<int>{1, 2, 3, 4, 5};

	// cout << *pd << endl << *pstr << endl;
	// for (const auto &v : *pv) {
	// 	cout << v << endl;
	// }

	// 3.值初始化。只需要在类型名后跟一对空括号即可。
	string *ps1 = new string;     // 默认初始化，调用string类的默认构造函数，为空string
	string *ps2 = new string();   // 值初始化，为空string
	int *pi1 = new int;           // 默认初始化，函数体内，所以*pi1的值是未定义的
	int *pi2 = new int();		  // 值初始化，*pi2为0

}

void new_const()
{
	const int *pci = new const int(1024);
	const string *pcs = new const string;  // 分配并默认初始化...
}

void reset_ptr()
{
	int *p(new int(42));  // p 指向动态内存
	auto q = p;  // p 和 q 指向相同的内存
	delete p;  // p 和 q 均变为无效
	p = nullptr;  // 指出 p 不在绑定到任何对象，但不能指明 q 也不绑定到任何对象上，所以上面才说这只是提供了有限的保护
}

// ==========================
vector<int>* make_vector()
{
	return new vector<int>;
}

void push_into_vector(vector<int>* pvi)
{
	int num;
	while (cin >> num) {
		pvi->push_back(num);
	}
}

void print_vector(vector<int>* pvi)
{
	for (const auto &num : *pvi) {
		cout << num << endl;
	}
}

void exercise1()
{
	auto pv = make_vector();
	push_into_vector(pv);
	print_vector(pv);
	delete pv;
	// pv = nullptr;
}

// ==============================
shared_ptr<vector<int>> make_vector_hxw()
{
	vector<int> temp = {1, 2, 3};
	// auto p = make_shared<vector<int>>(2, 1);
	auto p = make_shared<vector<int>>(temp);  // 这里涉及到几个知识点，make_shared的初始化方式，vector<>的初始化方式
	// auto p = make_shared<vector<int>>();
	return p;
}
void push_into_vector_hxw(shared_ptr<vector<int>> psv)
{
	int num;
	while (cin >> num) {
		psv->push_back(num);
	}
}
void print_vector_hxw(shared_ptr<vector<int>> psv)
{
	for (const auto &num : *psv) {
		cout << num << endl;
	}
}
void exercise2()
{
	auto pv = make_vector_hxw();
	push_into_vector_hxw(pv);
	print_vector_hxw(pv);
}

int main()
{
	// dynamic_allocate();
	// exercise1();
	exercise2();
	return 0;
}



