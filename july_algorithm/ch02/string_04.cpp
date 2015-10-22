/**********

【字符串查找问题 -- KMP】
主要：找最大相等的k前缀和k后缀

**********/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void GetNext(const string& pattern, vector<int>& next)
{
	const int size = pattern.size();
	next[0] = -1;

	int j = 0;
	int k = next[j];
	while (j < size - 1) {
		// k = next[j-1]，p[k]表示前缀，p[j]表示后缀
		// k == -1 表示未找到k前缀与j后缀相等，此时应该j往后移一位，k也应该加1变为0
		if (k == -1 || pattern[j] == pattern[k]) {
			++j;
			++k;
			next[j] = k;
		} else {
			k = next[k];
		}
	}
}

void GetNext2(const string& pattern, vector<int>& next)
{
	const int size = pattern.size();
	next[0] = -1;

	int j = 0;
	int k = next[0];
	while (j < size - 1) {
		if (k == -1 || pattern[j] == pattern[k]) {
			++j;
			++k;
			if (pattern[j] == pattern[k]) {
				next[j] = next[k];
			} else {
				next[j] = k;
			}
		} else {
			k = next[k];
		}
	}
}

int KMP(const string& str, const string& pattern)
{
	int ans = -1;
	int i = 0;
	int j = 0;
	int str_len = str.size();
	int pattern_len = pattern.size();

	vector<int> next(pattern_len);
	// GetNext1(pattern, next);
	GetNext2(pattern, next);

	while (i < str_len) {
		if (j == -1 || str[i] == pattern[j]) {
			++i;
			++j;
		} else {
			j = next[j];
		}

		// 匹配成功
		if (j == pattern_len) {
			ans = i - pattern_len;
			break;
		}
	}
	return ans;
}


int main()
{
	string str = "abababaabaabcabababab";
	string pat = "abaabcaba";

	cout << KMP(str, pat) << endl;

	return 0;
}
