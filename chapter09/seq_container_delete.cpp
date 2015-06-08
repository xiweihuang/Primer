// 顺序容器，删除元素


#include <stdio.h>
#include <deque>
#include <string>
#include <list>
#include <vector>

using namespace std;

void pop_oper() {
	deque<string> ds = {"Kobe", "Jordan", "James"};

	ds.pop_front();
	ds.pop_back();

	for (auto beg = ds.begin(); beg != ds.end(); ++beg) {
		printf("%s  ", (*beg).c_str());
	}
	printf("\n");
}

void erase_oper() {
	list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto it = lst.begin();
	while (it != lst.end()) {
		// if (*it & 1)
		// 	++it;
		// else
		// 	it = lst.erase(it);
		if (!(*it & 1))
			lst.erase(it);
		++it;
	}
	for (auto &val : lst)
		printf("%d\n", val);
}

void erase_area() {
	list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	lst.erase(++lst.begin(), lst.end());

	for (auto &val : lst)
		printf("%d\n", val);
}

// 将ia拷贝到一个vector和一个list中，使用单迭代器版本的erase从list中删除奇数元素，从vector中删除偶数元素
void erase_exercise() {
	int ia[] = {2, 10, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	deque<int> vi(begin(ia), end(ia));
	// vector<int> vi(ia, ia+11);
	list<int> li(ia, ia+11);

	auto it = vi.begin();
	// while (it != vi.end()) {
	// 	if (!(*it & 1))
	// 		vi.erase(it);
	// 	++it;  // 这种方式有没有问题？如果erase之后迭代器发生变化，那么++it，还会是下一个元素吗？
	// }
	// auto itn = ++it;

	auto itn = vi.erase(it);
	printf("------------- %d\n", *it);

	auto iter = li.begin();
	while (iter != li.end()) {
		if (*iter & 1)
			iter = li.erase(iter);  // 这是比较好的方法，不管迭代器是否失效，都能拿到下一个元素的迭代器
		else
			++iter;
	}

	for (auto &val : vi) {
		printf("%d\n", val);
	}

	for (auto &val : li) {
		printf("-- %d\n", val);
	}
}


int main()
{
	// pop_oper();
	// erase_oper();
	// erase_area();
	erase_exercise();
	return 0;
}
