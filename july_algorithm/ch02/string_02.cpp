/**********

【最长公共子序列】

子序列：一个序列S任意删除若干个字符得到新序列T，则T叫做S的子序列
最长公共子序列：两个序列X和Y的公共子序列中，长度最长的那个，定义为X和Y的最长公共子序列

· 13455 和 245576的最长公共子序列为455
· acdfg 和 adfc的最长公共子序列为adf(不要求连续的)

最长公共子串：最长公共子串要求连续


**********/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void LCS(const string& str1, const string& str2, string& str)
{
	const int size1 = str1.size() + 1;
	const int size2 = str2.size() + 1;

	int vc[size1][size2];
	for (int i = 0; i < size1; ++i)
		for (int j = 0; j < size2; ++j)
			vc[i][j] = 0;

	for (int i = 1; i < size1; ++i) {
		for (int j = 1; j < size2; ++j) {
			if (str1[i-1] == str2[j-1])
				vc[i][j] = vc[i-1][j-1] + 1;
			else
				vc[i][j] = max(vc[i-1][j], vc[i][j-1]);
		}
	}

	// 这里只是得到其中一个LCS，如果要得到所有的LCS，就要用深度/广度优先搜索
	int i = size1;
	int j = size2;
	while ((i != 0) && (j != 0)) {
		if (str1[i-1] == str2[j-1]) {
			str.push_back(str1[i-1]);
			--i;
			--j;
		} else {
			if (vc[i][j-1] > vc[i-1][j])
				--j;
			else
				--i;
		}
	}

	reverse(str.begin(), str.end());
}

int main()
{
	string str1 = "BCDABAB";
	string str2 = "CBACBAABA";
	string str;
	LCS(str1, str2, str);
	cout << str << endl;
	return 0;
}
