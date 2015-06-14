// vector::data
// 因为vector是连续存储的内存空间，所以这个data应该是返回首元素的指针(地址)

#include <stdio.h>
#include <vector>

using namespace std;

void test() {
	vector<int> vi = {10, 20, 30, 40, 50};
	// auto p = vi.data();
	int *p = vi.data();

	printf("%d\n", *(p+4));  // 10
}

int main()
{
	test();
	return 0;
}