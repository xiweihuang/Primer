#include <iostream>
using namespace std;

class Base1
{
public:
	virtual void f() { cout << "Base1::f" << endl; }
	virtual void g() { cout << "Base1::g" << endl; }
	virtual void h() { cout << "Base1::h" << endl; }
};

class Base2
{
public:
	virtual void f() { cout << "Base2::f" << endl; }
	virtual void g() { cout << "Base2::g" << endl; }
	virtual void h() { cout << "Base2::h" << endl; }
};

class Base3
{
public:
	virtual void f() { cout << "Base3::f" << endl; }
	virtual void g() { cout << "Base3::g" << endl; }
	virtual void h() { cout << "Base3::h" << endl; }
};

class Derive : public Base1, public Base2, public Base3
{
public:
	// virtual void f1() { cout << "Derive::f1" << endl; }
	virtual void f() { cout << "Derive::f" << endl; }
private:
	virtual void g1() { cout << "Derive::g1" << endl; }
};

typedef void(*Func)();

void test1()
{
	Derive d;
	auto v_func_ptr1 = (void**)*((void**)(&d) + 0);
	for (int i = 0; i < 5; ++i) {
		auto func = (Func)*(v_func_ptr1 + i);
		func();
	}
}

void test2()
{
	Derive d;
	int idx[] = {5, 3, 3};
	for (int i = 0; i < 3; ++i) {
		auto v_func_ptr = (void**)*((void**)&d + i);
		for (int j = 0; j < idx[i]; ++j) {
			auto func = (Func)*(v_func_ptr + j);
			func();
		}
		cout << "--------" << endl;
	}
}

void test3()
{
	Derive d;
	int idx[] = {4, 3, 3};
	for (int i = 0; i < 3; ++i) {
		auto v_func_ptr = (void**)*((void**)&d + i);
		for (int j = 0; j < idx[i]; ++j) {
			auto func = (Func)*(v_func_ptr + j);
			func();
		}
		cout << "--------" << endl;
	}
}

// 通过父类类型的指针访问之类自己的虚函数
// 访问non-public的虚函数 把Derive的g1函数的访问属性设为private
void test4()
{
	Base1* pb = new Derive();
	// pb->g1();  // 编译错误
	auto v_func_ptr = (int**)*(int**)pb;
	auto my_func_g1 = (Func)*(v_func_ptr + 3);
	my_func_g1();
}


int main()
{
	// cout << sizeof(Derive) << endl;  // 有三张虚函数表，所以类对象存放着三个指针，对于64位系统，64位是8个字节，所以三个指针就是24个字节
	// test1();
	// test2();
	// test3();
	test4();
	return 0;
}

