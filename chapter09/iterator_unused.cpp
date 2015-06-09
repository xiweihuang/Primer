// 容器操作可能使迭代器失效
// 向容器添加元素：
// 1. vector和string:
// 2. deque

#include <stdio.h>
#include <vector>
#include <string>
#include <deque>
#include <list>

using namespace std;

void update_iterator() {
	vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto iter = vi.begin();

	// 不要保存end返回的迭代器，因为添加/删除vector或string的元素后，或者deque中首元素之外任何位置添加/删除元素后，原来end返回的迭代器总是会失效
	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert(iter, *iter);

			// 这一句非常重要，因为我们在进行添加元素和删除元素操作时(insert和erase)，每次改变容器的操作后都要正确地重新定位迭代器
			// 这个时候向前移动迭代器，跳过当前元素以及插入到它之前的元素
			iter += 2;  
		} else {
			iter = vi.erase(iter);
		}
	}

	for (auto &val : vi) {
		printf("%d\n", val);
	}
}

void save_end_error() {
	
	auto begin = v.begin(), end = v.end();
}

int main()
{
	update_iterator();
	return 0;
}


// 1. 上面update_iterator()函数不能用于list或forward_list，为什么？修改程序，使之也能用于这些类型。
// 2. 上面程序，像下面语句这样调用insert是否合法？如果不合法，为什么？  iter = vi.insert(iter, *iter++);
// 3. 在
