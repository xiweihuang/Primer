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

// 要有"+"运算
void read_only_accumulate() {
	vector<int> vi = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sum = accumulate(vi.begin(), vi.end(), 0);
	printf("%d\n", sum);

	vector<string> vs = {"Kobe ", "Bryant", " & ", "Michael ", "Jordan"};
	auto str = accumulate(vs.cbegin(), vs.cend(), string(""));  // 第三个参数不能直接传""，因为""的类型是const char*，不能修改的，但实际上要允许修改
	printf("%s\n", str.c_str());
}

void read_only_equal() {
	vector<const char*> vc = {"Kobe", "Jordan", "James"};
	vector<string> vs = {"Kobe", "Jordan", "James", "Durcant"};
	if (vc.size() == vs.size()) {
		bool bSame = equal(vc.cbegin(), vc.cend(), vs.cbegin());  // 这样比较是有问题的，因为vc和vs的size()不一样，可能会导致程序出错，而两者的size()应该由程序员自己来维护
		printf("%d\n", bSame);
	} else {
		printf("vc.size() != vs.size()\n");
	}
}

// ===============
void write_element_fill() {
	vector<int> vi = {10, 20, 30};
	fill(vi.begin(), vi.end()-1, 0);
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
	// int a2[] = {1, 2};  // 比a1元素少，会报错吗？
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

void exercise_10_3();
void exercise_10_4();
void exercise_10_5();
void exercise_10_6();
void exercise_10_9();


int main()
{
	// read_only_accumulate();
	// read_only_equal();

	// write_element_fill();
	// write_element_fill_n();
	// write_element_back_inserter();
	// write_element_copy();
	// write_element_replace();

	// elimDups();

	// 练习
	// exercise_10_3();
	// exercise_10_4();
	// exercise_10_5();
	// exercise_10_6();
	exercise_10_9();
	return 0;
}

// 10.3 用accumulate求一个vector<int>中的元素之和
void exercise_10_3() {
	vector<int> vi = {50, 40, 30, 20, 10, 0};
	auto sum = accumulate(vi.begin(), vi.end(), 0);
	printf("%d\n", sum);
}

// 10.4 假定v是一个vector<double>，那么调用accumulate(v.cbegin(), v.cend(), 0)有何错误(如果存在的话)？
void exercise_10_4() {
	vector<double> vd = {1.1, 2.2, 3.3, 4.4, 5.5};
	auto sum = accumulate(vd.begin(), vd.end(), 0.0);
	printf("%lf\n", sum);
}

// 10.5 在本书对名册(roster)调用equal的例子中，如果两个名册中保存的都是c风格字符串而不是string，会发生什么？
void exercise_10_5() {
	// c风格的字符串，保存的是字符数组的指针，比较的是两个指针，那就肯定永远都不会相等。
	// 但是！！！
	// 对于字符串常量，编译器会优化，都是指向同一个地址。
	// 因此如下s1和s2的地址是一样的
	// 所以equal比较的是地址，也是一样的
	const char *s1 = "Kobe";
	const char *s2 = "Kobe";
	printf("%p\n", s1);
	printf("%p\n", s2);
	if (s1 == s2) {
		printf("Kobe's address is same...\n");
	}
	vector<const char *> v1 = {"Kobe", "Jordan"};
	vector<const char *> v2 = {"Kobe", "Jordan"};
	if (v1.size() == v2.size()) {
		bool bSame = equal(v1.begin(), v1.end(), v2.begin());
		printf("%d\n", bSame);
	} else {
		printf("size isn't same!\n");
	}
}


// 10.6 编写程序，使用fill_n将一个序列中的int值都设置为0
void exercise_10_6() {
	// vector<int> vi;
	// fill_n(back_inserter(vi), 10, 0);
	vector<int> vi = {10, 20, 30, 40, 50};
	fill_n(vi.begin(), vi.size(), 0);

	for (auto &val : vi) {
		printf("%d\n", val);
	}
}

// 10.7 
// 10.8 本节提到过，标准库算法不会改变它们所操作的容器的大小。为什么使用back_inserter不会使这一断言失效？
// 注意一点，泛型算法对于容器的要求并不是有足够的空间，而是要有足够的元素。算法不具备向容器添加元素的能力。应该是说传进去的普通迭代器没有向容器添加元素的功能，而back_inserter则具有这个能力。


// 10.9 实现你自己的elimDups。测试你的程序，分别在读取输入后、调用unique后以及调用erase后打印vector的内容。
void exercise_10_9() {
	vector<int> vi = {73, 12, 634, 12, 55, 67, 73, 12, 98, 99};

	sort(vi.begin(), vi.end());
	auto end_iter = unique(vi.begin(), vi.end());

	vi.erase(end_iter, vi.end());

	for (auto &val : vi) {
		printf("%d\n", val);
	}
}

// 10.10 你认为算法不改变容器大小的原因是什么？
// 算法只认迭代器
// 算法根本就不知道容器的存在。算法访问数据的唯一通道是迭代器。是否改变容器大小，完全是迭代器的选择和责任。
// 当我们向fill_n传递back_inserter时，虽然最终效果是向容器添加了新的元素，但对fill_n来说，根本不知道这回事。
// 它仍像往常一样（通过迭代器）向元素赋予新值，只不过这次是通过back_inserter来赋值，而back_inserter选择将新值添加到了容器而已。











