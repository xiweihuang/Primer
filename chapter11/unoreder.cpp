#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

void use_unordered_map() {
	// map<string ,size_t> word_count;
	unordered_map<string, size_t> word_count;
	string word;
	while (cin >> word)
		++word_count[word];
	for (const auto &w : word_count) {
		cout << w.first << ", " << w.second << endl;
	}
}

int main()
{
	use_unordered_map();
	return 0;
}
