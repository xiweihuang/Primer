#include <stdio.h>
#include <vector>
#include <string>
#include <list>

using namespace std;

void print_vector_int(vector<int>& vec) {
	for (auto &item : vec) {
		printf("%d, ", item);
	}
	printf("\n");
}

int main()
{
	// vector<int> v1 = {1, 2, 3, 4, 5};
	// vector<int> v2 = {50, 40, 30, 20, 10};

	// auto pi = v1.begin();

	// printf("item = %d\n", *pi);

	// // swap(v1, v2);
	// // v1.swap(v2);

	// // printf("item = %d\n", *pi);

	// // v1.assign(v2);  // 这是错误的
	// // v1.assign({5, 4, 3, 2, 1});  // 这是正确的
	// v1.assign(v2.begin(), v2.end());

	// printf("item = %d\n", *pi);

	// print_vector_int(v1);
	// print_vector_int(v2);

	// list<string> names;
	// vector<const char*> oldstyle;

	// // names = oldstyle;
	// names.assign(oldstyle.cbegin(), oldstyle.cend());

	list<const char*> lc = {"Kobe", "Jordan", "James"};
	vector<string> vs;

	vs.assign(lc.begin(), lc.end());

	for (auto &item : vs) {
		printf("%s  ", item.c_str());
	}
	printf("\n");

	return 0;
}