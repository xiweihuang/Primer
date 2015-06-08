// 顺序容器添加元素

// 顺序容器
// vector  string  deque  list  (forward_list  array) 这两个是c++11之后才有的

// push_back():  vector, string, deque, list
// push_front(): deque, list, forward_list
// insert():     vector, string, deque, list  (forward_list提供另外一个版本的insert)
// emplace()、emplace_back()、emplace_front() 和对应的 push 一样

// vector: push_back(), insert(), emplace_back(), emplace()
// string: push_back(), insert()
// deque:  push_back(), push_front(), insert(), emplace_back(), emplace_front(), emplace()
// list:   push_back(), push_front(), insert(), emplace_back(), emplace_front(), emplace()

// forward_list: 
// array:

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <deque>

using namespace std;

void pushItem() {
	vector<string> vs;
	string word;
	while (cin >> word)
		vs.push_back(word);

	for (auto &s : vs)
		cout << s << endl;

	list<int> ilist;
	for (size_t ix = 0; ix != 4; ++ix)
		ilist.push_front(ix);

	for (auto beg = ilist.cbegin(); beg != ilist.cend(); ++beg) {
		cout << *beg << endl;
	}
}

// insert 的基本用法
void insert_method() {
	// 在容器中的特定位置添加元素
	vector<string> svec;
	list<string> slist = {"Hello", "World"};

	// 1.接受一个迭代器作为第一个参数，制定元素插入到迭代器所指位置之前（返回新元素的迭代器）
	auto iter1 = slist.insert(slist.begin(), "Welcome!");
	// slist.push_front("Welcome");
	// cout << *iter1 << endl;

	// 2.接受一个元素数目和一个值（返回第一个新加入的元素的迭代器）
	auto iter2 = slist.insert(slist.end(), 10, "Anna");
	// cout << *(++iter2) << endl;

	// 3.接受一对迭代器（返回第一个新加入的元素的迭代器）
	vector<string> v = {"quasi", "simba", "frollo", "scar"};
	auto iter3 = slist.insert(slist.begin(), v.end() - 2, v.end());
	// cout << *iter3 << endl;

	// 4.接受一个初始化列表（返回第一个新加入的元素的迭代器）
	auto iter4 = slist.insert(slist.end(), {"these", "words", "will", "go", "at", "the", "end"});
	// cout << *iter4 << endl;

	// for (auto & val : slist)
	// 	cout << val << endl;
}

// 通过 insert 的返回值在容器中一个特定位置反复插入元素
void insert_in_same_pos() {
	vector<string> words = {"Kobe", "Jordan", "James"};
	auto iter = words.begin();
	++iter;
	for (size_t i = 0; i != 5; ++i) {
		iter = words.insert(iter, "NBA");
	}

	for (auto &val : words)
		cout << val << endl;
}

class Person {
public:
	// Person() = default;
	Person() {
		cout << "默认构造函数" << endl;
	}
	Person(string name) : name_(name) {
		cout << "构造函数1" << endl;
	}
	Person(string name, int age, bool sex) : name_(name), age_(age), sex_(sex) {
		cout << "构造函数2" << endl;
	}

public:  
	// string name_ = "UNKNOW";
	// int age_ = -1;
	// bool sex_ = false;

	string name_;
	int age_;
	bool sex_;
};

void emplace_basic() {
	deque<Person> dequePerson;
	dequePerson.emplace_back();
	dequePerson.emplace_back("Kobe");
	dequePerson.emplace_front("Jordan", 45, true);

	auto iter = dequePerson.begin();
	++iter;
	dequePerson.emplace(iter, "James", 30, true);

	for (auto &val : dequePerson) {
		printf("%s, %d, %d\n", val.name_.c_str(), val.age_, val.sex_);
	}
}

int main()
{
	// pushItem()
	// insert_method();
	// insert_in_same_pos();
	emplace_basic();
	

	return 0;
}