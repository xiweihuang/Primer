/* ===================================

【初始化的方法】

初始化的分类：
	·默认初始化
	·直接初始化（圆括号、花括号）
	·拷贝初始化（圆括号、花括号）
	·值初始化（圆括号、只提供数量，不提供初值）

两种基本的方式：
	①圆括号的构造方式
	②列表初始化，花括号{}

1.默认初始化，详细参考另外一份文档

2.直接初始化和拷贝初始化：(<<c++ primer>> P76)
	1.使用等号(=)初始化一个变量，是拷贝初始化
	2.反之，是直接初始化

	列表初始化：
	大多数情况下这些不同的初始化方式是可以相互等价使用，不过事实也并非一直如此。有如下例外情况：
	1.使用拷贝初始化(=)时，只能提供一个初始值
	2.如果提供的是一个类内初始值，则只能使用拷贝初始化、或花括号的形式初始化
	3.如果提供的是初始元素值的列表，则只能把初始值都放在花括号里进行列表初始化，而不能放在圆括号里

	概念：类内初始值
	c++11，一个类的数据成员，可以提供一个类内初始值，如果没有初始值的成员将被默认初始化
	使用：
		·只能拷贝初始化（如果可以用圆括号直接初始化，会被误认为是函数吧？）
		·放在花括号里
		·放在等号右边
		·不能使用圆括号

3.值初始化：(<<c++ primer>> P88)
以vector为例子，通常情况下，可以只提供vector对象容纳的元素数量而不用略去初始值，此时库会创建一个值初始化的元素初值，并把它赋给容器中的所有元素。
这个初值由vector对象中元素的类型决定。

*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 直接初始化和拷贝初始化
void test1()
{
	string s1 = "hiya";  // 拷贝初始化
	string s2("hiya");   // 直接初始化
	string s3(10, 'c');  // 直接初始化

}


// 列表初始化
void test2()
{
	// 列表初始化
	vector<string> articles = {"a", "an", "the"};
	vector<string> v1{"a", "an", "the"};

	// 错误
	// vector<string> v2("a", "an", "the");

	vector<int> ivec(10, -1);  // 情况1，不能使用拷贝初始化
}


// 类内初始值
class Person
{
public:
	void output()
	{
		cout << name << endl;
		for (const auto &n : friends) {
			cout << n << endl;
		}
	}
private:
	string name = "NULL";
	vector<string> friends = {"Kobe", "Jordan"};
};
void test3()
{
	Person p;
	p.output();
}

int main()
{
	test3();
	return 0;
}




