// 额外的string操作

// 构造: 
/*
	方法1：
	string s1
	string s2(s1)
	string s2 = s1
	string s3("value")
	string s3 = "value"
	string s4(n, 'c')
*/

/*
	方法2：
	string s{a, b, c...}
	string s = {a, b, c...}
	string s(b, e) -- 迭代器
	string s(n) -- n个元素
	string s(n, t)
*/

/*
	方法3：
	string s(cp, n)  -- cp指向的数组中前n个字符的拷贝
	string s(s2, pos2)  -- s2从下标pos2开始的字符的拷贝
	string s(s2, pos2, len2)  -- s2从下标pos2开始len2个字符的拷贝
*/

#include <stdio.h>
#include <string>
#include <vector>
#include <time.h>
// #include <iostream>

using namespace std;

void string_init() {
	const char *cp = "Hello World!!!";
	char noNull[] = {'H', 'i'};
	string s1(cp);
	string s2(noNull, 2);
	string s3(noNull);  // 未定义，因为noNull不是以空字符结束的，一直从内存找到'\0'为止
	string s4(cp+6, 5);
	string s5(s1, 6, 5);
	string s6(s1, 6);
	string s7(s1, 6, 20);  // 是正确的，虽然20超出s1的长度，但是也只拷贝到s1的末尾
	// string s8(s1, 16);  // 错误，s1的index没有16

	printf("%s\n", s7.c_str());
}

void string_substr() {
	string s = "hello world";
	string s2 = s.substr(0, 5);
	string s3 = s.substr(6);
	string s4 = s.substr(6, 11);
	// string s5 = s.substr(12);
	string s5 = "temp";
	printf("%s--%s--%s--%s\n", s2.c_str(), s3.c_str(), s4.c_str(), s5.c_str());
}

void exercise1();
void exercise2();
void exercise2_count_time();

int main() 
{
	// string_init();
	// string_substr();
	// exercise1();
	// exercise2();
	exercise2_count_time();
	return 0;
}


// 1. 编写程序，从一个vector<char>初始化一个string。
void exercise1() {
	vector<char> vc = {'K', 'o', 'b', 'e', 'B', 'r', 'y', 'a', 'n', 't'};
	string s1(vc.begin()+1, vc.end());
	string s2(vc.data(), vc.size());

	// printf("%s\n", s1.c_str());
	printf("%s\n", s2.c_str());
}

// 2. 假定你希望每次读取一个字符存入一个string中，而且知道最少需要读取100个字符，应该如何提高程序的性能。
void exercise2_count_time() {
	auto start = clock();

	exercise2();

	auto finish = clock();
	auto total = static_cast<double>((finish - start)/CLOCKS_PER_SEC);

	printf("程序运行时间 = %lf\n", total);

}

void exercise2() {
	// 方法1（超级快）  如果初始指定reserve会不会更快
	vector<char> vc;
	vc.reserve(100000000);

	for (size_t i = 0; i != 100000000; ++i) {
		vc.push_back('a');
	}

	string str(vc.begin(), vc.end());

	// 方法3（直接用数组）不支持这么大的数组
	// char ch[100000000];
	// for (size_t	i = 0; i != 100000000; ++i) {
	// 	ch[i] = 'a';
	// }
	// ch[100000000-1] = '\0';
	// string str(ch);

	// 方法2（非常糟糕）
	// string str = "";
	// for (size_t i = 0; i != 1000000; ++i) {
	// 	str = str + 'a';
	// }

	// printf("%lu\n", vc.capacity());
	printf("%c\n", str[1]);
}





