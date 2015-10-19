// 动态数组
// 两种一次分配一个对象数组的方法：
// 1. new
// 2. allocator

#include <iostream>

using namespace std;

int get_size() {
	return 5;
}

// new和数组
void new_array() {
	// 1.
	// 类型名后跟一对方括号，在其中指明要分配的对象的数目
	// 方括号中的大小必须是整型，但不必是常量
	int *pia = new int[get_size()];  // pia指向第一个int

	// 2.
	// 也可以用一个表示数组类型的类型别名来分配一个数组，这样，new就不需要方括号了
	typedef int arrT[42];
	int *p = new arrT;
}

// 动态数组并不是数组类型，所以不能调用begin和end，也不能使用范围for语句来处理其中的元素
void dy_array_not_array() {
	int *p = new int[5];

	// 错误，没有begin方法，不能用范围for语句
	// for (auto &v : (*p)) {
	// 	cout << v << endl;
	// }
	for (size_t i = 0; i != 5; ++i) {
		cout << *(p+i) << endl;
	}

	int a[5] = {10, 20, 30, 40, 50};
	for (auto &v : a) {
		cout << v << endl;
	}
}

// 初始化动态分配对象的数组(注意！是数组)
void init_new_array() {
	// 1. 默认初始化
	int *pia = new int[10];  // 10个未初始化的int
	string *psa = new string[10];  // 10个空string

	// 2. 可以对数组中的元素进行值初始化，方法是在大小之后跟一对空括号
	int *pia2 = new int[10]();  // 10个值初始化为0的int
	string *psa2 = new string[10]();  // 10个空string

	// 3. 新标准中，还可以提供一个“元素初始化器”的花括号列表
	int *pia3 = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	string *psa3 = new string[10]{"a", "an", "the", string(3, 'x')};  // 前4个用给定的初始化器初始化，剩余的进行值初始化

	// 注意，如果初始化器的数目大于元素数目，则new表达式失败，不会分配任何内存
}

// 动态分配一个空数组？
void empty_array() {
	char arr[0];  // 错误：不能定义长度为0的数组。不能创建一个大小为0的静态数组对象
	char *cp = new char[0];  // 正确：但cp不能解引用

	// cp 是一个合法的非空指针，像"尾后指针"一样。注意，cp不能解引用！！！
}

// 释放动态数组
void delete_array() {
	// 为了释放动态数组，我们使用一种特殊形式的 delete -- 在指针前加上一个空方括号对
	int *p  = new int(5);
	int *pa = new int[10]();

	delete p;  // p 必须指向一个动态分配的对象或为空
	delete[] pa;  // pa必须指向一个动态分配的数组或为空

	// 逆序！！！ 数组中的元素按逆序销毁

}

// 智能指针和动态数组
void unique_ptr_and_array() {
	// 标准库提供了一个可以管理new分配的数组的unique_ptr版本
	// 需要在对象类型
}

int main()
{
	// new_array();
	// dy_array_not_array();
	// init_new_array();
	// empty_array();
	delete_array();
	return 0;
}