#include "my_StrBlob.h"
#include <exception>

using namespace std;

StrBlob::StrBlob() : _data(make_shared<vector<string>>()) 
{
}

StrBlob::StrBlob(initializer_list<string>& il) : _data(make_shared<vector<string>>(il)) 
{
}

void StrBlob::check(size_type i, const string &msg) 
{
	if (i >= _data->size())
		throw out_of_range(msg);
}

size_type StrBlob::size() const 
{
	return _data->size();
}

bool StrBlob::empty() const 
{
	return _data->empty();
}

void StrBlob::push_back(const string &s) 
{
	_data->push_back(s);
}

void StrBlob::pop_back() 
{
	check(0, "pop_back on empty StrBlob");
	_data->pop_back();
}

inline string& StrBlob::front() 
{
	check(0, "front on empty StrBlob");
	return _data->front();
}

inline string& StrBlob::back() 
{
	check(0, "back on empty StrBlob");
	return _data->back();
}

inline const string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return _data->front();
}

inline const string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return _data->back();
}
