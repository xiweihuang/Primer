/**********

【最长括号匹配】
给定字符串，仅包含左括号'('和右括号')'
它可能不是括号匹配的，设计算法，找出最长匹配的括号子串，返回该子串的长度
如：
(():2
()():4
()(()):6
(()()):6

注意，下面GetMatchLength()这种方法应该是有问题的
如 (()()(()
GetMatchLength()得到的是6
而正确答案应该是4
因为这里要求的是连续的最长的括号匹配

**********/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
bool IsLeftChar(char ch)
{
	return ch == '(';
}
bool IsMatch(char ch1, char ch2)
{
	return (ch1 == '(' && ch2 == ')');
}

int GetMatchLength(const string& str)
{
	stack<char> s;
	int cnt = 0;
	for (auto ch : str) {
		if (IsLeftChar(ch) || s.empty())
			s.push(ch);
		else if (IsMatch(s.top(), ch)) {
			// 出栈，计数值x2
			s.pop();
			cnt += 2;
		}
	}
	return cnt;
}
*/


// 正确的方法
int GetLongestParenthese(const string& str) 
{
	int size = str.size();
	stack<int> s;
	int answer = 0;  // 最终解
	int start = -1;  // 左括号前一个位置
	for (int i = 0; i < size; ++i) {
		if (str[i] == '(')
			s.push(i);
		else {
			if (s.empty())
				start = i;
			else {  // 只有在右括号和左括号发生匹配时，才有可能更新最终解
				s.pop();
				if (s.empty())
					answer = max(answer, i-start);
				else
					answer = max(answer, i-s.top());
			}
		}
	}
	return answer;
}


// 方法2，考虑到只有在右括号和左括号发生匹配时，才有可能更新最终解
// 但是为了防止，左括号比右括号多的情况，还需要逆向再做一次
// 用deep代替了stack，空间复杂度为 O(1)
int GetLongestParenthese2(const string& str)
{
	int deep = 0;
	int start = -1;
	int answer = 0;
	int size = str.size();
	for (int i = 0; i < size; ++i) {
		if (str[i] == '(')
			++deep;
		else {
			--deep;
			if (deep == 0) {
				answer = max(answer, i-start);
			} else if (deep < 0) {  // 右括号数目比左括号多了。等于这里就截断了
				deep = 0;
				start = i;
			}
		}
	}

	deep = 0;
	start = size;
	for (int i = size-1; i >= 0; --i) {
		if (str[i] == ')')
			++deep;
		else {
			--deep;
			if (deep == 0) {
				answer = max(answer, start - i);
			} else if (deep < 0) {
				deep = 0;
				start = i;
			}
		}
	}
	return answer;
}




int main()
{
	string str1 = "(((()()))";
	string str2 = "(()()(()()()()()";
	string str3 = "()(())";
	string str4 = "(()())";
	cout << GetLongestParenthese2(str1) << endl;
	cout << GetLongestParenthese2(str2) << endl;
	cout << GetLongestParenthese2(str3) << endl;
	cout << GetLongestParenthese2(str4) << endl;
	return 0;
}