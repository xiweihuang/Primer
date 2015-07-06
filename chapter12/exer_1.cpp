#include <stdio.h>
#include <memory>
#include <vector>

using namespace std;

// vector<int>* func1() {
// 	return new vector<int>();
// }
shared_ptr<vector<int>> func1() {
	// return new vector<int>();
	return make_shared<vector<int>>();
}

// void func2(vector<int>* ptr) {
// 	int i = 0;
// 	scanf("%d", &i);
// 	ptr->push_back(i);
// }
void func2(shared_ptr<vector<int>> &ptr) {
	int i = 0;
	scanf("%d", &i);
	ptr->push_back(i);
}

// void func3(vector<int>* ptr) {
// 	for (const auto &val : (*ptr)) {
// 		printf("%d\n", val);
// 	}
// }
void func3(shared_ptr<vector<int>> &ptr) {
	for (const auto &val : (*ptr)) {
		printf("%d\n", val);
	}
}

void exercise_12_06() {
	auto ptr = func1();
	func2(ptr);
	func3(ptr);
	// delete ptr;
}

int main()
{
	exercise_12_06();
	return 0;
}