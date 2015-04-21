#include <iostream>
#include <vector>
#include <string>

using namespace std;

const string &shorterString(const string &s1, const string &s2)
{
	return (s1.size() <= s2.size() ? s1 : s2);
}

char &get_val(string &str, string::size_type ix)
{
	return str[ix];
}

vector<string> process(int a)
{
	if (a > 0) {
		return {};
	} else if (a == 0) {
		return {"Hello", "World"};
	} else {
		return {"What", "a", "wonderful", "world"};
	}
}

int factorial(int val)
{
	if (val > 1)
		return factorial(val - 1)*val;
	return 1;
}

int &get(int *array, int index)
{
	return array[index];
}

using Iter = vector<string>::iterator;

void print(Iter beg, Iter end)
{
	if (beg != end) {
		cout << *beg << endl;
		print(++beg, end);
	}
}

int main()
{
	// string s1 = "hello";
	// string s2 = "world";
	// const string &s3 = shorterString(s1, s2);
	// s1 = "hellllll";  // s3是cons只不过是s3自以为是而已，s3自己遵守不去修改所引用的值，但是s1不是const，那么它是可以修改值的
	// cout << s3 << endl;


	// string s("a value");
	// cout << s << endl;
	// get_val(s, 0) = 'A';
	// cout << s << endl;

	// vector<string> vs = process(-1);
	// for (auto s : vs) {
	// 	cout << s << endl;
	// }

	// auto res = factorial(5);
	// cout << res << endl;

	// int ia[10];
	// for (int i = 0; i != 10; ++i) {
	// 	get(ia, i) = i;
	// }
	// cout << ia[1] << endl;

	vector<string> vs = {"Hello", "World"};
	print(vs.begin(), vs.end());

	return 0;
}











