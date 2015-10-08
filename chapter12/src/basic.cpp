#include <stdio.h>
#include <memory>
#include <string>
#include <vector>

using namespace std;

void test1()
{
	shared_ptr<int> p3 = make_shared<int>(42);  // new int(42)
	shared_ptr<string> p4 = make_shared<string>(10, '9');  // new string(10, '9')
	auto p5 = make_shared<int>();  // new int;

	// int *p3 = new int(42);
	// string *p4 = new string(10, '9');
	// auto p5 = new int();

	printf("%d\n", *p3);
	printf("%s\n", p4->c_str());
	// printf("%s\n", p4);
	printf("%d\n", *p5);
}

void test2()
{
	auto q = make_shared<int>(12);  // 12:1
	auto r = make_shared<int>(42);  // 42:1
	r = q;  // 42:0 12:2

	printf("%ld\n", q.use_count());  // 2
	printf("%ld\n", r.use_count());  // 2
}

shared_ptr<int> factory()
{
	return make_shared<int>();
}

void use_factory()
{
	auto p = factory();  // 发生了赋值动作，p的计数值加1
	// return p;  // p 这个 shared_ptr 的计数值加1，此时为2

	// 退出该函数后，p 会被释放，会调用p的析构函数，把引用计数值减1
}

void test3()
{
	vector<string> v1;
	{
		vector<string> v2 = {"a", "an", "the"};
		v1 = v2;
	}
	for (const auto &v : v1) {
		printf("%s\n", v.c_str());
	}
}

int main()
{
	// test1();
	// test2();
	test3();
	return 0;
}
