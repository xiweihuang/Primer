#include <iostream>
#include <map>
#include <vector>

using namespace std;

pair<string, int> process(vector<string> &v) {
	if (!v.empty())
		return {v.back(), v.back().size()};
	else
		return pair<string, int>();
}

void exercise_11_12();
void exercise_11_14();

int main()
{
	// pair<string, size_t> word_count("Kobe", 4);
	// cout << word_count.first << ", " << word_count.second << endl;

	// map<string, int> mp = {{"Kobe", 4}};
	// for (const auto &val : mp) {
	// 	cout << val.first << val.second << endl;
	// }

	// exercise_11_12();
	exercise_11_14();
	return 0;
}

// 11.12
void exercise_11_12() {
	vector<pair<string, int>> vec;
	vec.push_back(make_pair("Kobe", 35));
	vec.push_back(make_pair("Jordan", 40));
	vec.push_back(pair<string, int>("Jame", 30));
	pair<string, int> dur = {"Durant", 25};
	vec.push_back(dur);
	vec.push_back({"Duncan", 38});

	for (auto iter = vec.cbegin(); iter != vec.cend(); ++iter) {
		cout << (*iter).first << ", " << (*iter).second << endl;
	}
}

void exercise_11_14() {
	map<string, vector<pair<string, string>>> mp;
	// mp["Michael"] = {};
	mp["Michael"].push_back(make_pair("Jordan", "4-15"));
	mp["Michael"].push_back({"Miller", "8-19"});
	for (auto &val : mp) {
		for (const auto &vv : val.second) {
			cout << vv.first << ", " << vv.second << endl;
		}
	}
}
