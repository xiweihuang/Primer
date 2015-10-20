/**********

【逆波兰表达式RPN】
逆波兰表达式，Reverse Polish Notation，又叫后缀表达式


**********/

#include <vector>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

bool IsOperator(const string& str)
{
	return (str == "+" || str == "-" || str == "*" || str == "/");
}

int Calculate(int a, int b, const string& oper)
{
	int result = 0;
	if (oper == "+")
		result = a + b;
	else if (oper == "-")
		result = a - b;
	else if (oper == "*")
		result = a * b;
	else if (oper == "/")
		result = a / b;
	return result;
}

int ReversePolishNotation(const vector<string>& strVec)
{
	stack<int> s;
	for (const auto& str : strVec) {
		if (!IsOperator(str)) {
			s.push(stoi(str));
		} else {
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			int result = Calculate(a, b, str);
			s.push(result);
		}
	}
	return s.top();
}

int main()
{
	vector<string> vs = {"2", "1", "+", "3", "*"};
	cout << ReversePolishNotation(vs) << endl;
	return 0;
}
