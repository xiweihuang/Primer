// 改变容器大小

#include <stdio.h>
#include <list>

using namespace std;

void example1() {
	list<int> ilist(10, 42);
	ilist.resize(15);
	ilist.resize(25, -1);
	ilist.resize(5);

	for (auto &val : ilist) {
		printf("%d\n", val);
	}
}

int main()
{
	example1();
	return 0;
}

// 1. 假定vec包含25个元素，那么vec.resize(100)会做什么？如果接下来调用vec.resize(10)会做什么？
// 2. 接受单个参数的resize版本对元素类型有什么限制（如果有的话）？