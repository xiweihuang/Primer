#include "StrBlob.h"

using namespace std;

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {

}
StrBlob::StrBlob(std::initializer_list<string> il) : data(make_shared<vector<string>>(il)) {

}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}

size_type StrBlob::size() const {
	return data->size();
}
bool StrBlob::empty() const {
	return data->empty();
}

void StrBlob::push_back(const string &t) {
	data->push_back(t);
}
void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

string& StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data->front();
}

string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::check(size_type i, const string &msg) const {
	if ( i >= data->size())
		throw std::out_of_range(msg);
}