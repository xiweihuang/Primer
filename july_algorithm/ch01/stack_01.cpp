/**********

【栈--括号匹配】
给定字符串，仅由"()[]{}"六个字符组成。设计算法，判断该字符串是否有效

**********/

#include <stack>
#include <iostream>
#include <string>
using namespace std;

bool IsLeftChar(char c)
{
	if (c == '(' || c == '{' || c == '[')
		return true;
	return false;
}

bool IsCharMatch(char topCh, char curCh)
{
	if ((topCh == '(' && curCh == ')') ||
		(topCh == '{' && curCh == '}') ||
		(topCh == '[' && curCh == ']')) {
		return true;
	}
	return false;
}


bool IsStrMatch(const string& str)
{
	stack<char> charStack;
	for (auto ch : str) 
	{
		if (IsLeftChar(ch))
			charStack.push(ch);
		else
		{
			if (charStack.empty() || !IsCharMatch(charStack.top(), ch))
				return false;
			charStack.pop();
		}
	}
	return charStack.empty();
}



int main()
{
	string str = "(({})[])[()]";
	cout << IsStrMatch(str) << endl;
	return 0;
}







