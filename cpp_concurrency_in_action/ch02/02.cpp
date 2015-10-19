#include <iostream>
#include <thread>

using namespace std;

void do_something(int i)
{
	cout << "do_something: " << i;
}

struct func
{
	int& i_;
	func(int& i) : i_(i) {}
	void operator () ()
	{
		for (unsigned j = 0; j < 1000000; ++j) {
			do_something(i_);
		}
		cout << endl;
	}
};

// void oops()
// {
// 	int some_local_state = 0;
// 	func my_func(some_local_state);
// 	thread my_thread(my_func);
// 	my_thread.detach();
// }

// 使用RAII等待线程完成
class thread_guard
{
public:
	explicit thread_guard(thread& t) : t_(t) {}
	~thread_guard()
	{
		if (t_.joinable())
			t_.join();
	}
	thread_guard(thread_guard const &) = delete;
	thread_guard& operator = (thread_guard const &) = delete;
private:
	thread& t_;
};

void test1()
{
	int some_local_state = 0;
	func my_func(some_local_state);
	thread t(my_func);
	thread_guard g(t);

}

int main()
{
	// oops();
	test1();
	return 0;
}