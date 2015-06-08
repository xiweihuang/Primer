// #include <stdio.h>

// int main()
// {
// 	printf("hello world...%d\n", 1);
// 	return 0;
// }

#include <stdio.h>
#include <iostream>
#include <string>

int main()
{
	char a[20];
	int i = snprintf(a, 9, "%012d", 12345);
	// printf("i = %d, a = %s\n", i, a);
	std::string str(a);
	// std::cout << a << std::endl;
	printf("%s\n", str.c_str());
	return 0;
}
