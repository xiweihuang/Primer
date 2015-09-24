#include "StrBlob.h"

using namespace std;

inline
StrBlob::StrBlob() : data_(make_shared<vector<string>>())
{
}


inline
StrBlob::StrBlob(initializer_list<string> il) : data_(make_shared<vector<string>>(il))
{
}

inline
void StrBlob::push_back(const string &t)
{
	data_->push_back(t);
}

inline
void StrBlob::pop_back()
{
	data_->pop_back();
}

inline
string& StrBlob::front()
{
	return data_->front();
}


inline
string& StrBlob::back()
{
	return data_->back();
}

// int main()
// {
// 	StrBlob sb1;
// 	sb1.size();
// 	return 0;
// }