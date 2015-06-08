// 访问元素
// 包括 array 在内的每个顺序容器都有一个 front 成员函数，而除 forward_list 之外的所有容器都有一个 back 成员函数
// front 和 back 分别返回首元素和尾元素的引用
// at 和下表操作只适用于 string、vector、deque 和 array
// back 不适用于 forward_list

#include <stdio.h>
#include <vector>

using namespace std;

void visit_basic() {
	vector<int> vi = {5, 4, 3, 2, 1};

	if (!vi.empty()) {
		vi.front() = 50;
		auto &v = vi.back();
		v = 1024;
		// auto v2 = vi.back();  
		auto &v2 = vi.back();
		v2 = 0;
	}

	for (auto &val : vi)
		printf("%d  ", val);
	printf("\n");
}

// 下表操作和安全的随机访问
// 提供快速随机访问的容器(string, vector, deque和array)都提供下标运算符，返回的也是引用
void safe_visit() {
	vector<int> vs;
	// printf("%d\n", vs[0]);
	printf("%d\n", vs.at(0));
	printf("...\n");
}

void exercise2() {
	vector<int> vi;

	auto item1 = vi.at(0);
	auto item2 = vi[0];
	auto item3 = vi.front();

	auto iter = vi.begin();
	auto item4 = *iter;
}

int main()
{
	// visit_basic();
	// safe_visit();
	exercise2();
	return 0;
}
