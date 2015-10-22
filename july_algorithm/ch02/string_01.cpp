/**********

【字符串循环左移】

给定一个字符串S[0...N-1],要求把S的前k个字符移动到S的尾部
如把字符串“abcdef”前面的2个字符‘a’、‘b’移动到字符串的尾部,得到新字符串“cdefab”.即字符串循环左移k。
 多说一句:循环左移k位等价于循环右移n-k位。 
 算法要求:
 时间复杂度为 O(n),空间复杂度为 O(1)。

**********/

#include <iostream>
#include <string>
#include <time.h>
using namespace std;

void ReverseString(char* s, int from, int to)
{
	while (from < to) {
		char temp = s[from];
		s[from++] = s[to];
		s[to--] = temp;
	}

}

void LeftRotateString(char* s, int n, int m)  // n:字符串长度  m:左右前m位
{
	m %= n;  // "abcdef" 左移8位和左移2位是一样的！！！很关键
	ReverseString(s, 0, m - 1);
	ReverseString(s, m, n - 1);
	ReverseString(s, 0, n - 1);
}

void test1()
{
	char s[] = "abcdef";
	LeftRotateString(s, 6, 8);
	// cout << s << endl;
}


// 用string
void ReverseString2(string& str, int from, int to)
{
	while (from < to) {
		swap(str[from], str[to]);
		++from;
		--to;
	}
}
void LeftRotateString2(string& str, int n, int m)
{
	m %= n;
	ReverseString2(str, 0, m - 1);
	ReverseString2(str, m, n - 1);
	ReverseString2(str, 0, n - 1);
}
void test2()
{
	string s = "abcdef";
	LeftRotateString2(s, 6, 8);
	// cout << s.c_str();
}

int main()
{
	clock_t start, finish;
	start = clock();

	// 执行的工作
	// test1();
	test2();

	finish = clock();  
   	double totaltime = (double)(finish-start)/CLOCKS_PER_SEC;  
   	cout << totaltime*1000 << "ms" << endl;
	
	return 0;
}