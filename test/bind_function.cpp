#include <iostream>
#include <string>
#include <functional>

using namespace std;

int maxNumber(int a, int b)
{
	return (a > b ? a : b);
}

class Person
{
public:
	Person(string n, int a) : name(n), age(a) {}
	void show() const {
		cout << name << " , " << age << endl;
	}
private:
	string name;
	int age;
};

void function_example()
{
	// 普通函数
	// function<int(int, int)> myfunc1 = maxNumber;
	auto myfunc1 = maxNumber;
	cout << myfunc1(5, 6) << endl;

	// lambda
	// function<int(int, int)> myfunc2 = [](int a, int b){ return (a > b ? a : b); };
	auto myfunc2 = [](int a, int b){ return (a > b ? a : b); };
	cout << myfunc2(6, 5) << endl;

	// 类的非静态成员函数，要用bind
	Person p1("Kobe", 35);
	function<void()> myfunc3 = bind(&Person::show, p1);
	myfunc3();

}

// ==================================================

void func1(int x, int y, int z)
{
	cout << x << " , " << y << " , " << z << endl;
}

void func2(int& a, int& b)
{
	++a;
	++b;
	cout << a << " , " << b << endl;
}

class Function
{
public:
	void func3(int m, int n) {
		cout << m << " , " << n << endl;
	}
	static void func4(int m, int n) {
		cout << m << " , " << n << endl;
	}
};

void bind_example()
{
	function<void()> f1 = bind(func1, 11, 22, 33);
	f1();

	// function<void(int,int)> f2 = bind(func1, 11, placeholders::_2, placeholders::_1);
	// f2(55, 66);  // 11 66 55

	function<void(int, int)> f2 = bind(func1, placeholders::_1, placeholders::_2, 33);
	f2(11, 22);  // 11 22 33

	function<void(int, int)> f3 = bind(func1, placeholders::_2, placeholders::_1, 33);
	f3(22, 11);  // 11 22 33

	int n = 2;
	int m = 3;
	// function<void(int&)> f4 = bind(func2, n, placeholders::_1);
	auto f4 = bind(func2, n, placeholders::_1);
	f4(m);  // 3 4

	cout << n << endl;  // 2
	cout << m << endl;  // 4

	Function ffun;
	auto f5 = bind(&Function::func3, ffun, placeholders::_1, placeholders::_2);
	f5(10, 20);  // 10 20

	

}


int main()
{
	// function_example();
	bind_example();
	return 0;
}