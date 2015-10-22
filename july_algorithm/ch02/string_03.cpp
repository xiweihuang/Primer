/**********

【字符串查找问题 -- 暴力求解】


**********/

#include <iostream>
#include <string>
using namespace std;


int BruteForceSearch(const string& str, const string& pat)
{
	int i = 0;  // 当前匹配到的原始串首位
	int j = 0;  // 模式串的匹配位置
	int size1 = str.size();
	int size2 = pat.size();
	int last = size1 - size2;

	while ((i <= last) && (j < size2)) {
		if (str[i+j] == pat[j])
			++j;
		else {  // 不匹配，则比对下一个位置，模式串回溯到首位
			++i;
			j = 0;
		}
	}

	if (j >= size2)
		return i;
	return -1;
}


int main()
{
	string str = "ABCDE";
	string pat = "DE";
	cout << BruteForceSearch(str, pat) << endl;
	return 0;
}