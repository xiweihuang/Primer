#include "StrBlob.h"
#include <iostream>
using namespace std;

void test1()
{
	// StrBlob sb1({"a", "an", "the"});
	StrBlob sb1;
	{
		StrBlob sb2({"a", "an", "the"});
		sb1 = sb2;

		cout << sb1.size() << endl;
	}

	cout << sb1.size() << endl;

}

int main()
{
	test1();
	return 0;
}
