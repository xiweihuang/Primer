#include <stdio.h>
#include <string>
#include <list>
#include <vector>
#include <deque>
#include <forward_list>

using namespace std;

int main()
{
	list<string> authors = {"Milton", "Shakespeare", "Austen"};
	vector<const char*> articles = {"a", "an", "the"};

	list<string> list2(authors); // right
	// deque<string> authList(authors); //wrong
	// vector<string> words(articles); //wrong

	// 使用迭代器参数来拷贝一个范围时，容器类型和元素类型都可以不同，但是元素类型要能实现转换
	forward_list<string> words(articles.begin(), articles.end());

	// 与顺序容器大小相关的构造函数
	vector<int> ivec(10, -1);

	// 6种创建和初始化 vector 对象的方法
	vector<int> v1;
	vector<int> v2 = v1;
	vector<int> v3(v2);

	vector<int> v4 = {1, 2, 3};
	vector<int> v5{1, 2, 3};

	vector<int> v6(10);
	vector<int> v7(10, 1);

	// 还有一种是，通过传递迭代器参数
	vector<int> v8(v1.begin(), v1.end());


	list<int> li = {1, 2, 3};
	vector<double> vd(li.begin(), li.end());

	vector<int> vi = {10, 20, 30};
	vector<double> vdd(vi.begin(), vi.end());

	for (auto &item : vd) {
		printf("%lf  ", item);
	}
	printf("\n");

	for (auto beg = vdd.begin(); beg != vdd.end(); ++beg) {
		printf("%lf   ", *beg);
	}
	printf("\n");


	return 0;
}