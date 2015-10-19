#include <iostream>
using namespace std;

class Base 
{
public:
	virtual void f() { cout << "Base::f" << endl; }
	virtual void g() { cout << "Base::g" << endl; }
	virtual void h() { cout << "Base::h" << endl; }
};

class Derive : public Base
{
public:
	// virtual void f1() { cout << "Derive::f1" << endl; }
	virtual void f() { cout << "Derive::f" << endl; }
	virtual void g1() { cout << "Derive::g1" << endl; }
	virtual void h1() { cout << "Derive::h1" << endl; }
};

typedef void(*Func)();
void test1();
void test2();

int main() 
{
	// test1();
	test2();
	return 0;
}

void test2()
{
	Derive d;
	auto v_tab_ptr = (void**)(&d);  // 对象实例d的首地址，强转成一个存放指针的地址（里面存放的是虚函数表的地址）
	auto v_fun_ptr = (void**)(*v_tab_ptr);  // 虚函数表的地址

	const int V_FUN_NUM = 5;
	for (int i = 0; i < V_FUN_NUM; ++i) {
		auto func = (Func)*(v_fun_ptr + i);
		func();
	}

	cout << "-------------" << endl;

	Base* b = new Derive();
	b->f();
	auto base_v_fun_ptr = (void**)*(void**)b;
	for (int i = 0; i < 5; ++i) {
		auto func = (Func)*(base_v_fun_ptr + i);
		func();
	}

}


// 比较乱，稍微看看就行。这里只是试验了不同的强转方式而已
void test1()
{
	Base b;
	Func pFun = NULL;
	cout << "虚函数表地址：" << (long*)(&b) << endl;
	cout << "虚函数表--第一个函数地址：" << (long*)*(long*)(&b) << endl;

	cout << "==============" << endl;
	typedef void* (*pointer_type);

	cout << "虚函数表地址：" << &b << endl;
	cout << "虚函数表--第一个函数地址：" << *(pointer_type)(&b) << endl;

	auto virtual_mem_ptr = *(pointer_type)(&b);
	auto virtual_fun_ptr = (pointer_type)virtual_mem_ptr;

	auto pf = (Func)*(virtual_fun_ptr + 0);
	pf();
	auto pg = (Func)*(virtual_fun_ptr + 1);
	pg();
	auto ph = (Func)*(virtual_fun_ptr + 2);
	ph();
}

