#include <iostream>
using namespace std;

/*
【单一的一般继承】
	1.虚函数表在最前面的位置
	2.成员变量根据其继承和声明顺序依次放在后面
	3.在单一的继承中，被override的虚函数在虚函数表中得到了更新
*/

class Parent
{
public:
	long iparent;
	Parent() : iparent(10) {}
	virtual void f() { cout << "Parent::f()" << endl; }
	virtual void g() { cout << "Parent::g()" << endl; }
	virtual void h() { cout << "Parent::h()" << endl; }
};

class Child : public Parent
{
public:
	long ichild;
	Child() : ichild(100) {}
	virtual void f() { cout << "Child::f()" << endl; }
	virtual void g_child() { cout << "Child::g_child()" << endl; }
	virtual void h_child() { cout << "Child::h_child()" << endl; }
};

class GrandChild : public Child
{
public:
	long igrandchild;
	GrandChild() : igrandchild(1000) {}
	virtual void f() { cout << "GrandChild::f()" << endl; }
	virtual void g_child() { cout << "GrandChild::g_child()" << endl; }
	virtual void h_grandchild() { cout << "GrandChild::h_grandchild()" << endl; }
	// void test() { cout << "GrandChild::test()" << endl; }
};

int main()
{
	typedef void(*Fun)();
	GrandChild gc;
	auto pVtab = (long**)&gc;

	cout << "[0] GrandChild::_vptr->" << endl;
	// for (int i = 0; (Fun)pVtab[0][i] != NULL; ++i) {
	for (int i = 0; i < 6; ++i) {
		auto pFun = (Fun)pVtab[0][i];
		cout << " [" << i << "]";
		pFun();
	}

	cout << "[1]Parent.iparent = " << (long)pVtab[1] << endl;
	cout << "[2]Child.ichild = " << (long)pVtab[2] << endl;
	cout << "[3]GrandChild.igrandchild = " << (long)pVtab[3] << endl;
	// auto func = (Fun)pVtab[4];
	// func();

	return 0;
}
