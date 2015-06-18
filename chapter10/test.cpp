#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Person {
public:
	Person(const string &name) : name_(name) {}
	string getName() const {
		return name_;
	}
private:
	string name_;
};

// Primer 232页
// 常量对象，以及常量对象的引用或指针都只能调用常量成员函数
void print_person_name(const Person &p) {
	// printf("%s\n", p.getName().c_str());
	cout << p.getName() << endl;
}

int main()
{
	Person p("Kobe");
	print_person_name(p);

	return 0;
}