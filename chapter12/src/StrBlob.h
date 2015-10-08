#ifndef STR_BLOB_H
#define STR_BLOB_H

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>

using namespace std;

class StrBlob
{
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);

	size_type size() const { return data_->size(); }
	bool empty() const { return data_->empty(); }

	void push_back(const std::string &t);
	void pop_back();

	std::string& front();
	std::string& back();

	const std::string& front() const
	{
		return data_->front();
	}
	const std::string& back() const
	{
		return data_->back();
	}


private:
	std::shared_ptr<std::vector<std::string>> data_;
	// void check()
};


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



#endif