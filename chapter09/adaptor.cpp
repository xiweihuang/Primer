// 容器适配器
// stack, queue, priority_queue

#include <stdio.h>
#include <string>
#include <stack>
#include <queue>

using namespace std;

void stack_basic() {
	stack<int> intStack;
	for (size_t ix = 0; ix != 10; ++ix) {
		intStack.push(ix);
	}
	while (!intStack.empty()) {
		int value = intStack.top();
		printf("%d\n", value);
		intStack.pop();
	}
}

void queue_basic() {
	queue<int> qs;
	for (int ix = 0; ix != 10; ++ix) {
		qs.push(ix);
	}
	while (!qs.empty()) {
		int value = qs.front();
		printf("%d\n", value);
		qs.pop();
	}
}

// 在push的时候会根据优先级插入到合适位置。 使用 < 运算符来确定优先级
void priority_queue_basic() {
	priority_queue<int> pi;
	for (int ix = 0; ix != 10; ++ix) {
		pi.push(ix);
	}
	while (!pi.empty()) {
		// int value = pi.front();
		int value = pi.top();
		printf("%d\n", value);
		pi.pop();
	}
	// 9 8 7 ...
}

void exercise1(const string &);

int main()
{
	// stack_basic();
	// queue_basic();
	// priority_queue_basic();
	exercise1("Kobe(1996)Jordan");
	return 0;
}


// 1. 使用stack处理括号化的表达式。当你看到一个左括号，将其记录下来。当你在一个左括号之后看到一个右括号，从stack中pop对象，直至遇到左括号，将左括号也一起弹出栈。
void exercise1(const string &str) {
	// str = "abc(fko9)kfjs";
	stack<char> si;

	bool push_state = false, pop_state = false;
	for (auto idx = str.begin(); idx != str.end(); ++idx) {
		if (*idx == '(') {  // 入栈
			push_state = true;
			pop_state = false;
		} else if (*idx == ')') {
			pop_state = true;
			push_state = false;
		}

		if (push_state)
			si.push(*idx);
		if (pop_state) {
			while (!si.empty()) {
				auto val = si.top();
				printf("%c\n", val);
				si.pop();
			}
		}
	}
}

// 然后将一个值（括号内的运算结果）push到栈中，表示一个括号化的(子)表达式已经处理完毕，被其运算结果所替代。



