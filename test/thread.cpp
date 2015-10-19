#include <thread>
#include <iostream>

using namespace std;

int a = 10;
void hello()
{
	a = 100;
	cout << "hello..." << endl;
}

int main()
{
	thread t(hello);
	t.detach();

	for (int i = 0; i < 10000000; ++i);

	cout << a << endl;
	return 0;
}