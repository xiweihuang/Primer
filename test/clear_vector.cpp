#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> v;

	for (int i = 0; i < 1000000; ++i)
		v.push_back("abcdefghijklmn");

	cout << "vector capacity: " << v.capacity() << endl;

	// 正确清理一个vector的方法
	v.clear();
	vector<string>(v).swap(v);

	cout << "vector capacity: " << v.capacity() << endl;

	return 0;
}
