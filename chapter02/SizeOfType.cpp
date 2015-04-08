#include <iostream>
using namespace std;

int main()
{
	// bool b = 42;
	// int i = b;
	// // i = 3.14; // warning
	// cout << i << endl;

	// int i = -1;
	// if (i)
	// 	cout << "true" << endl;
	// else
	// 	cout << "false" << endl;

	// 列表初始化
	// int a = 0;
	// int b = {0};
	// // int c{0};
	// int d(0);

	// cout << a << b << d << endl;

	// 默认初始化
	// 如果是内置类型的变量未被显式初始化，它的值由定义的位置决定。
	// 定义于任何函数体之外的变量被初始化为0
	// 定义于函数体内部的内置类型变量将不被初始化

	// // 引用
	// int ival = 1024;
	// int &refVal = ival;

	// refVal = 2048;
	// cout << ival << endl;

	// // int ival2;
	// // int &refVal2; // 引用必须被初始化，且引用无法重新绑定到另外一个对象。

	// // 赋值永远改变的时等号左侧的对象
	// pi = &ival;
	// *pi = 0;

	// int num1 = 10, num2 = 20;
	// int *p = &num1;
	// cout << p << endl;
	// p = &num2;
	// cout << p << endl;
	// *p = 30;
	// cout << num2 << endl;

	// // =======================
	// // 如何理解以下定义?
	// int ival = 1024;
	// int *pi = &ival;
	// int **ppi = &pi;

	// // 最简单的方法是从右往左阅读r的定义
	// // 离变量名最近的符号(&r的&)对变量的类型有着最直接的影响,因此r是一个引用
	// // 声明符的其余部分用于确定r引用的类型是什么，此例中的*说明r引用的是一个指针
	// int i = 42;
	// int *p;
	// int *&r = p;

	// =======================
	


	return 0;
}

























