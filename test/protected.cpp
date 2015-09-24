#include <iostream>

using namespace std;

class Person
{
public:
	Person(int a, int b) : x(a), y(b) {}
protected:
	int x;
	int y;
};

class Student : public Person
{
public:
	Student(int a, int b) : Person(a, b) {}
	void output() {
		cout << x << y << endl;
	}
};

int main()
{
	Student s(10, 20);
	s.output();
	return 0;
}