// 理解算法的最基本的方法就是了解它们是否读取元素、改变元素或是重排元素顺序

// 只读算法
// find  count  accumulate(#include <numeric>)  equal

// 写容器元素的算法
// fill  fill_n  back_insert  copy  replace  replace_copy

// 重排容器元素的算法
// sort


#include <stdio.h>
#include <numeric>
#include <vector>
#include <string>
#include <iterator>
#include <list>

using namespace std;

void read_only_accumulate() {
	vector<int> vi = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sum = accumulate(vi.begin(), vi.end(), 0);
	printf("%d\n", sum);

	vector<string> vs = {"Kobe ", "Bryant", " & ", "Michael ", "Jordan"};
	auto str = accumulate(vs.cbegin(), vs.cend(), string(""));
	printf("%s\n", str.c_str());
}

void read_only_equal() {
	vector<const char*> vc = {"Kobe", "Jordan", "James"};
	vector<string> vs = {"Kobe", "Jordan", "James", "Durcant"};
	bool bSame = equal(vc.cbegin(), vc.cend(), vs.cbegin());  // 这样比较是有问题的，因为vc和vs的size()不一样，可能会导致程序出错，而两者的size()应该手动来维护
	printf("%d\n", bSame);
}

// ===============
void write_element_fill() {
	vector<int> vi = {10, 20, 30};
	fill(vi.begin(), vi.end(), 0);
	for (auto &val : vi) {
		printf("%d\n", val);
	}
}
void write_element_fill_n() {
	vector<int> vi = {10, 20, 30, 40, 50};
	fill_n(vi.begin(), 3, 0);
	for (auto &val : vi) {
		printf("%d\n", val);  // 0 0 0 40 50
	}

	// 初学常犯的错误，在空容器上调用fill_n。因为最多写入与给定序列一样多的元素
	// vector<int> vec;
	// fill_n(vec.begin(), 10, 0);
}

// back_inserter  插入迭代器
// #include <iterator>
void write_element_back_inserter() {
	// vector<int> vec;
	// auto it = back_inserter(vec);
	// *it = 10;
	// *it = 20;
	// *it = 30;
	// for (auto &val : vec) {
	// 	printf("%d\n", val);
	// }

	vector<int> vec;
	fill_n(back_inserter(vec), 10, 1);
	for (auto &val : vec) {
		printf("%d\n", val);
	}

}

void write_element_copy() {
	int a1[] = {10, 20, 30};
	// int a2[sizeof(a1)/sizeof(*a1)];  // 和a1元素一样多
	int a2[] = {1, 2, 3, 4, 5};  // 比a1元素多
	auto ret = copy(begin(a1), end(a1), a2);

	for (auto &val : a2) {
		printf("%d\n", val);
	}
	if (ret == end(a2))
		printf("end of a2...\n");
}

void write_element_replace() {
	list<int> li = {2, 1, 0, 4321, 2, 0, 21, 22, 0, 0};

	// 在原序列上替换
	// replace(li.begin(), li.end(), 0, 100);
	// for (auto &val : li) {
	// 	printf("%d\n", val);
	// }

	// 保留原序列不变
	vector<int> vec;
	replace_copy(li.begin(), li.end(), back_inserter(vec), 0, 100);  // 第三个迭代器参数，指出调整后序列的保存位置

	for (auto &val : li) {
		printf("%d\n", val);
	}
	printf("==========\n");

	for (auto &val : vec) {
		printf("%d\n", val);
	}
}

// ========================
// sort:利用元素类型的<运算符来实现排序的
void elimDups() {
	vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	sort(words.begin(), words.end());

	// unique重排输入范围，使得每个单词只出现一次
	// 排列在范围的前部，返回指向不重复区域之后一个位置的迭代器
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());

	for (auto &val : words) {
		printf("%s\n", val.c_str());
	}
}


int main()
{
	// read_only_accumulate();
	// read_only_equal();

	// write_element_fill();
	// write_element_fill_n();
	// write_element_back_inserter();
	// write_element_copy();
	// write_element_replace();

	elimDups();
	return 0;
}

// 10.3 用accumulate求一个vector<int>中的元素之和
// 10.4 假定v是一个vector<double>，那么调用accumulate(v.cbegin(), v.cend(), 0)有何错误(如果存在的话)？
// 10.5 在本书对名册(roster)调用equal的例子中，如果两个名册中保存的都是c风格字符串而不是string，会发生什么？


// 10.6 编写程序，使用fill_n将一个序列中的int值都设置为0
// 10.7 
// 10.8 本节提到过，标准库算法不会改变它们所操作的容器的大小。为什么使用back_inserter不会使这一断言失效？


// 10.9 实现你自己的elimDups。测试你的程序，分别在读取输入后、调用unique后以及调用erase后打印vector的内容。
// 10.10 你认为算法不改变容器大小的原因是什么？











