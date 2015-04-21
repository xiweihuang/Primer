// #include <iostream>
// #include "base.h"

// int main()
// {
// 	for (std::size_t i = 0; i != 10; i++)
// 		std::cout << count_calls() << std::endl;
// 	std::cout << "fda;f" << std::endl;
// 	return 0;
// }


#include <iostream>
#include <string>

using namespace std;

void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void swap(int &num1, int &num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

int addTwoNumber(const int &num1, const int &num2)
{
	return (num1 + num2);
}

void find_char(const string &str, const char &c, string::size_type &first, int &time)
{
	for (auto ch : str) {
		if (ch == c) {
			
		}
	}
}

int main()
{
	// int a = 10, b = 20;
	// // swap(&a, &b);
	// swap(a, b);
	// cout << "a=" << a << ", b=" << b << endl;

	// int a = 10, b = 20;
	// cout << addTwoNumber(a, b) << endl;

	int i = 42;
	const int *cp = &i;
	const int &r = i;
	const int &r2 = 42;

	int *p = cp;
	int &r3 = r;
	int &r4 = 42;

	// const int ci = 42;
	// int i = ci;
	// int * const p = &i;




	return 0;
}