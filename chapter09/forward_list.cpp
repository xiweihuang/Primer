// 特殊的forward_list操作
// 记住两句话
// 1.forward_list中，当添加或删除一个元素时，删除或添加的元素之前的那个元素的后继会发生变化。
// 2.在一个单向链表中，没有简单的方法来获取一个元素的前驱。

// before_begin()   cbefore_begin()
// insert_after(p, t)
// insert_after(p, n, t)
// insert_after(p, b, e)
// insert_after(p, il)
// emplac_after(p, args)
// erase_after(p)
// erase_after(b, e)

#include <stdio.h>
#include <forward_list>
#include <string>

using namespace std;

void example1() {
	forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end()) {
		if (*curr % 2)
			curr = flst.erase_after(prev);
		else {
			prev = curr;
			++curr;
		}
	}
	for (auto &val : flst) {
		printf("%d\n", val);
	}
}

void test() {
	forward_list<int> fi = {10, 20, 30, 40, 50};
	auto prev = fi.before_begin();
	auto curr = fi.begin();

	prev = curr;
	++curr;
	// prev->10, curr->20

	curr = fi.erase_after(prev);
	// prev->10, curr->30

	printf("%d\n", *prev);
	printf("%d\n", *curr);
}

void exerise1() {
	forward_list<int> fi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto prev = fi.before_begin();
	auto curr = fi.begin();
	while (curr != fi.end()) {
		if (*curr % 2) {
			curr = fi.erase_after(prev);
		} else {
			prev = curr;
			++curr;
		}
	}
	for (auto &val : fi) {
		printf("%d\n", val);
	}
}

void func2(forward_list<string> &fs, const string &s1, const string &s2) {
	auto prev = fs.before_begin();
	auto curr = fs.begin();
	auto flag = false;
	while (curr != fs.end()) {
		if (*curr == s1) {
			flag = true;
			prev = curr;
			curr = fs.insert_after(prev, s2);
		} else {
			prev = curr;
			++curr;
		}
	}
	if (!flag) {
		fs.insert_after(prev, s2);
	}
}
void exerise2() {
	forward_list<string> fs = {"Kobe", "Jordan", "James"};
	func2(fs, "Kobe1", "NBA");

	for (auto &val : fs) {
		printf("%s\n", val.c_str());
	}
}

int main()
{
	// test();
	// example1();
	// exerise1();
	exerise2();
	return 0;
}

// 1. 编写程序，查找并删除forward_list<int>中的奇数元素
// 2. 编写函数，接受一个forward_list<string>和两个string共3个参数。函数应在链表中查找第一个string，并将第二个string插入到紧接着第一个string之后的位置。若第一个string未在链表中，则将第二个string插入到链表末尾。


