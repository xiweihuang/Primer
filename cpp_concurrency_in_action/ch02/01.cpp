/* ============================

【第2章 线程管理】
·启动新线程
·等待线程与分离线程
·线程唯一标识符

【2.1 线程管理基础】
每个c++程序至少有一个线程：该线程用于执行main()函数。程序中其他线程可以使用其他的入口函数，之后，这些线程与原始线程（已main()作为入口函数的线程）同时运行
当线程中的入口函数执行完毕后，该线程就会推出

◀️启动线程
	构造std::thread对象
		void do_some_work();
		std::thread my_thread(do_some_work);
	没有参数，没有返回值
	在代码中，提供的函数对象会复制到新线程的存储空间当中，函数对象的执行和调用都在线程的内存空间中进行.
	函数对象的副本与原始的函数对象的行为是相同的

	1.当你启动了线程，要明确一下自己的决定。
		a.等待线程结束（加入式）
		b.自主运行（分离式）
	如果在thread对象销毁之前没有做出决定，那么程序就会终止，thread的析构函数会调用terminate()，抛出异常
	因此需要确保线程能够正确地加入(join)或者分离(detach)
	为了防止线程访问已经销毁的变量，可以将数据复制到线程中，而不是复制到共享数据中
	使用一个能访问局部变量的函数去创建一个线程是一个糟糕的主意，除非十分确定线程会在函数完成前结束。此外，你也可以通过加入的方式来确保线程在函数完成前结束。

◀️等待线程完成
	如果需要等待线程结束，相关的thread实例需要使用join()，可以确保局部变量在线程完成后，才被销毁。
	调用join()，还清理了线程相关的存储部分，这样thread对象将不再与已经完成的线程有任何关联。这意味着，你只能对一个线程使用一次join()，一旦已经使用过join()，thread对象就不能再次加入了。

◀️特殊情况下的等待
	

◀️后台运行线程
	对一个thread对象使用detach()就会将这个线程搁置在后台运行，这就意味着不能与这个线程产生直接交互。也就是说，我们不会等待这个线程结束。
	如果一个线程被分离，那么就不可能让一个thread对象引用它，所以这个线程就不可能再被加入。
	通常，称分离线程为守护线程

*/


#include <iostream>
#include <thread>
using namespace std;


void do_some_work() { cout << "do_some_work!" << endl; }
void do_something() { cout << "do_something!" << endl; }
void do_something(int i) { cout << i; }
void do_something_else() { cout << "do_something_else!" << endl; }

// ---------------------------------
class background_task
{
public:
	void operator()()  // 运算符重载
	{
		a = 20;
		do_something();
		do_something_else();
		cout << a << endl;
	}
	int a = 10;
};

void test1()
{
	// thread my_thread(do_some_work);

	background_task f;
	thread my_thread(f);

	// thread my_thread(background_task());  // 编译错误
	// thread my_thread((background_task()));
	// thread my_thread{background_task()};

	// thread my_thread([](){
	// 	do_something();
	// 	do_something_else();
	// });

	my_thread.join();

	cout << f.a << endl;
}


// --------------------------------
int a = 10;
struct func
{
	int& i;
	func(int& i_) : i(i_) {}
	void operator () ()
	{
		a = 20;
		for (unsigned j = 0; j < 100; ++j) {
			do_something(i);
		}
		cout << endl;
	}
};

void test2()
{
	int idx = 0;
	func my_func(idx);
	thread my_thread(my_func);
	my_thread.detach();

	// for (int i = 0; i < 100000000; ++i);
	// cout << a << endl;

	// my_thread.join();
}





int main()
{
	// test1();
	test2();
	return 0;
}