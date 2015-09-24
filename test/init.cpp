#include <iostream>
#include <string>
#include <vector>

using namespace std;

void init()
{
	int *pi = new int;
	cout << *pi << endl;

	// int *pi = new int();
}

class Person {
public:
	int a[5];
	void print() {
		for (int i = 0; i < 5; ++i) {
			cout << a[i] << ", ";
		}
		string s;
		cout << s << endl;
	}
};

Person p1;

int main()
{
	// init();

	Person p2;
	p1.print();  // p1是全局的，那么p1.a也是全局的
	p2.print();  // p2是局部的

	// 容器
	string s;
	cout << s << endl;

	vector<int> vi(10);
	for (auto &v : vi) {
		cout << v << endl;
	}

	return 0;
}

