/**********

【KMP应用--PowerString问题】
给定一个长度为n的字符串S,如果存在一个 字符串T,重复若干次T能够得到S,那么, S叫做周期串,T叫做S的一个周期。
如:字符串abababab是周期串,abab、ab都 是它的周期,其中,ab是它的最小周期。
设计一个算法,计算S的最小周期。如果S不 存在周期,返回空串。

**********/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void GetNext(const string& pattern, vector<int>& next)
{
	int size = pattern.size();
	next[0] = -1;
	int j = 0;
	int k = next[0];
	while (j < size) {
		if (k == -1 || pattern[j] == pattern[k]) {
			++j;
			++k;
			next[j] = k;
		} else {
			k = next[k];
		}
	}
}

int main()
{
	string str = "abcabcabcabc";
	vector<int> next(str.size()+1);
	GetNext(str, next);

	int k = next.back();
	int p = str.size() - k;
	if (str.size() % p == 0) {
		string min_str(str, 0, p);
		cout << min_str << endl;
	}

	return 0;
}
