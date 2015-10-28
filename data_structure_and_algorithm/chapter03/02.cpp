#include <iostream>
#include <stack>
#include <string>
// using namespace std;

bool IsOperator(const char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool ProrityHighThanTop(char ch, char top)
{
	if (top == '(') {
		return false;
	}
	if (top == '*' || top == '/')
		return false;

	return (ch == '*' || ch == '/');
}

std::string ToSuffix(const std::string& str)
{
	std::string newStr;
	std::stack<char> stk;

	for (size_t i = 0; i < str.size(); ++i) {
		char checkChar = str[i];
		if (checkChar == '(')
			stk.push(checkChar);
		else if (checkChar == ')') {
			while (!stk.empty()) {
				char top = stk.top();
				if (top != '(') {
					newStr += top;
					stk.pop();
				} else {
					stk.pop();
					break;
				}
			}
		} else if (IsOperator(checkChar)) {
			while (!stk.empty()) {
				char top = stk.top();
				if (top == '(')
					break;
				if (ProrityHighThanTop(checkChar, top)) {
					break;
				} else {
					newStr += stk.top();
					stk.pop();
				}
			}
			stk.push(checkChar);
		} else {
			newStr += checkChar;
		}
	}

	while (!stk.empty()) {
		newStr += stk.top();
		stk.pop();
	}
	return newStr;
}


// int FindResult(std::stack<int>& s, char op)
// {
// 	int a = stoi(s.top());
// 	s.pop();
// 	int b = stoi(s.top());
// 	s.pop();

// 	int res = 0;
// 	if (op == '+')
// 		return a + b;
// 	if (op == '-')
// 		return a - b;
// 	if (op == '*')
// 		return a * b;
// 	return a / b;
// }

// int Cal(const std::string& str)
// {
// 	std::stack<int> stk;
// 	int result = 0;
// 	for (size_t i = 0; i < str.size(); ++i) {
// 		char ch = str[i];
// 		if (IsOperator(ch)) {
// 			int res = FindResult(stk, ch);
// 			result += res;
// 			stk.push(res);
// 		} else {
// 			stk.push(ch);
// 		}
// 	}
// 	return result;
// }

int main()
{
	std::string str1 = "a+b*c+(d*e+f)*g";
	std::string str2 = ToSuffix(str1);
	std::cout << str2 << std::endl;
	// std::cout << Cal(str2) << std::endl;
	return 0;
}