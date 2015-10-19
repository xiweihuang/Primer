#include <iostream>
using namespace std;

class Base
{
public:
	// Base();
	virtual ~Base() 
	{
		cout << "Base destruct" << endl;
	}
private:
	int b;
};

class Derived : public Base
{
public:
	virtual ~Derived()
	{
		cout << "Derived destruct" << endl;
	}
private:
	int i;
	int j;
};


int main()
{
	// Base* pBase = new Derived[10];
	// delete[] pBase;

	// Base* pBase[10];
	// for (int i = 0; i < 10; ++i) {
	// 	pBase[i] = new Derived[10];
	// }
	// delete[] pBase;

	// Base* pBase = new Derived[10];  // pBase是一个指针，指向一个Base对象

	// Derived d[10];
	// Base* pBase = d;  // pBase也是一个指向Base对象的指针

	cout << sizeof(Base) << endl;
	cout << sizeof(Derived) << endl;

	Base* pb = new Derived[2];
	delete[] pb;


	return 0;
}