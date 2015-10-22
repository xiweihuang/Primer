#include <iostream>
using namespace std;

int LocalMaximum(const int* A, int size)
{
	int left = 0;
	int right = size - 1;
	int mid;
	while (left < right)
	{
		mid = (left + right) / 2;
		cout << mid << endl;
		if ((A[mid] > A[mid+1]))
			right = mid;
		else
			left = mid + 1;
	}
	return A[left];
}

int main()
{
	int A[] = {1, 2, 3, 4, 5, 8, 6};
	cout << LocalMaximum(A, 7);
	return 0;
}
