// vector对象是如何增长的
// vector要连续存储，且大小可变。只能分配新的内存空间来保存已有元素和新增元素。但是必须要采取适当的策略，以减少上述的操作
// 通常分配的空间要比所需的空间大

// 管理容量的成员函数
// size():已经保存了多少元素
// capacity():最多可以保存多少元素
// reserve():分配至少能容纳n个元素的内存空间(不会退回内存空间的)

// capacity() 和 reserve() 只适用于 vector 和 string
// shrink_to_fit 只适用于 vector、string 和 deque

#include <stdio.h>
#include <vector>
#include <deque>

using namespace std;

void capacity_and_size() {
	vector<int> ivec;

	for (vector<int>::size_type ix = 0; ix != 24; ++ix) {
		ivec.push_back(ix);
	}

	ivec.reserve(50);

	// 接下来把预留空间用光
	while (ivec.size() != ivec.capacity())
		ivec.push_back(0);

	printf("size = %lu, capacity = %lu\n", ivec.size(), ivec.capacity());

	// 这个时候再添加一个新元素，大小就会超过capacity()，即超过50，vector就要重新分配空间
	ivec.push_back(123);

	// 其策略可能是在每次需要分配新内存空间时将当前容量翻倍
	printf("size = %lu, capacity = %lu\n", ivec.size(), ivec.capacity());  // size = 51, capacity > 51(clang++下为100)

	// 可以调用shrink_to_fit来要求vector将超出当前大小的多余内存退回给系统
	ivec.shrink_to_fit();
	printf("size = %lu, capacity = %lu\n", ivec.size(), ivec.capacity());  // size = 51, capacity > 51(clang++下为100)
}

// 测试一下vector的insert操作，是否size和capacity相等
// 只有push_back()为了高效率才会有这样的策略
void test_vector_insert() {
	vector<int> vi;
	for (int ix = 0; ix != 24; ++ix) {
		vi.push_back(ix);
	}

	vi.shrink_to_fit();

	vi.insert(vi.begin(), 100);
	printf("size = %lu, capacity = %lu\n", vi.size(), vi.capacity());

	// deque<int> di = {10, 20};
	// capacity 和 reserve 只适用于 vector 和 string
	// di.reserve(10);
	// printf("size = %lu, capacity = %lu\n", di.size(), di.capacity());

}

int main()
{
	// capacity_and_size();
	test_vector_insert();
	return 0;
}


// 1. 解释一个vector的capacity和size有何区别。
// 2. 一个容器的capacity可能小于它的size吗？
// 3. 为什么list或array没有capacity成员函数？
// 4. 编写程序，探究在你的标准库实现中，vector是如何增长的。
// 5. 解释下面程序片段做了什么：

// vector<string> svec;
// svec.reserve(1024);
// string word;
// while (cin >> word)
// 	svec.push_back(word);
// svec.resize(svec.size()+svec.size()/2);

// 6. 如果上一题的程序读入了256个词，在resize之后容器的capacity可能是多少？如果读入了512个、1000个或1048个词呢？














