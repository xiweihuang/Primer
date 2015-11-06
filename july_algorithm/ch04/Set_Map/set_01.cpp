#include <string>
#include <set>
#include <map>
#include <iostream>
using namespace std;

void test1()
{
	map<string, size_t> word_count;
	set<string> exclude = {
		"The", "But", "And", "Or", "An", "A",
		"the", "but", "and", "or", "an", "a"
	};

	string word;
	while (cin >> word) {
		if (exclude.find(word) == exclude.end())
			++word_count[word];
	}

	for (const auto& w : word_count) {
		cout << w.first << " occurs " << w.second << (w.second > 1 ? "times" : "time") << endl;
	}
}

int main()
{
	test1();
	return 0;
}