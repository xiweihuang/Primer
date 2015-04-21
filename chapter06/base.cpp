// #include <iostream>

// using namespace std;
#include <iostream>
#include "base.h"

std::size_t count_calls()
{
	static std::size_t ctr = 0;
	return ++ctr;
}

// int main()
// {
// 	for (size_t i = 0; i != 10; i++)
// 		cout << count_calls() << endl;
// 	return 0;
// }



// #include <iostream>
// #include "base.h"

// using namespace std;

// int main()
// {
// 	for (size_t i = 0; i != 10; i++)
// 		std::cout << count_calls() << std::endl;
// 	return 0;
// }
