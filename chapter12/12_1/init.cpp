#include <stdio.h>
#include <memory>
#include <string>
#include <vector>

using namespace std;

void test()
{
	shared_ptr<int> p3 = make_shared<int>(42);
	shared_ptr<string> p4 = make_shared<string>(10, '9');
	shared_ptr<int> p5 = make_shared<int>();

	auto p6 = make_shared<vector<string>>();
}

class Person
{
public:
	Person()
	{
		printf("Person 构造\n");
	}
	~Person()
	{
		printf("Person 析构\n");
	}
};

shared_ptr<Person> test_shared_ptr_person()
{
	auto p = make_shared<Person>();
	return p;
}

int main()
{
	auto p = test_shared_ptr_person();
	return 0;
}