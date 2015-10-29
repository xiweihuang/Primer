/**********

【第一个缺失的整数】
 给定一个数组A[0...N-1],找到从1开始,第 一个不在数组中的正整数。
 如3,5,1,2,-3,7,14,8输出4。


 整理算法描述:
 若A[i]=i,i加1,继续比较后面的元素。
 若A[i]<i或A[i]>N或A[A[i]]=A[i],丢弃A[i] 
 若A[i]>i,则将A[A[i]]和A[i]交换。


**********/

#include <iostream>
using namespace std;

// start:开始的最小值
int FirstMissNumber3(int* a, int size, int start)
{
	int cur = 0;
	int end = size - 1;
	while (cur <= end) {
		if (a[cur] == cur + start) {
			++cur;
		} else if (a[cur] < cur + start || a[cur] > start + end || a[cur] == a[a[cur] - start]) {
			a[cur] = a[end];
			--end;
		} else {
			swap(a[cur], a[a[cur] - start]);
		}
	}
	
	// 当 cur == 0, 其实表示没有找到指定的最小值

	return cur + start;
}

// 这里 a-- 
// 为的就是模拟数组下标从1开始
int FirstMissNumber2(int* a, int size)
{
	a--;
	int i = 1;
	while (i <= size) {
		if (a[i] == i) {
			++i;
		} else if (a[i] < i || a[i] > size || a[i] == a[a[i]]) {
			a[i] = a[size];
			--size;
		} else {
			swap(a[a[i]], a[i]);
		}
	}
	return i;
}

int main()
{
	int a[] = {3, 5, 1, 2, -3, 6, 4, 8};
	// int m = FirstMissNumber(a, sizeof(a) / sizeof(int));
	// int m = FirstMissNumber2(a, sizeof(a) / sizeof(int));
	int m = FirstMissNumber3(a, sizeof(a) / sizeof(int), 6);
	cout << m << endl;
	return 0;
}


