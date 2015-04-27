#include <iostream>
#include <vector>

using namespace std;

int sum(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a * b;
}
int divv(int a, int b) {
	return a/b;
}

typedef int (*pf)(int, int);


int main()
{
	// std::vector<pf> v;
	std::vector<function<int(int, int)>> v;
	v.push_back(sum);
	v.push_back(sub);
	v.push_back(mul);
	v.push_back(divv);

	// for (auto &func : v) {
	// 	int s = func(1, 2);
	// 	cout << s << endl;
	// }

	for (auto beg = v.begin(); beg != v.end(); ++beg) {
		// int s = 
		auto p = *beg;
		// int s = (*p)(1, 2);
		int s = p(1, 2);
		cout << s << endl;
	}
	return 0;
}