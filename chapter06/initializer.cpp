#include <iostream>
#include <initializer_list>

using namespace std;

int cal_sum(initializer_list<int> &list)
{
	int sum = 0;
	for (auto i = list.begin(); i != list.end(); ++i) {
		sum += *i;
	}
	return sum;
}
int main()
{
	// int mysum = cal_sum({1,2,3,4,5});
	initializer_list<int> li = {1,2,3,4,5};
	int mysum = 0;
	mysum = cal_sum({1,2,3,4,5});
	cout << mysum << endl;
	return 0;
}


