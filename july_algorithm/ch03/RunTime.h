#ifndef RUNTIME_H
#define RUNTIME_H

#include <iostream>
#include <time.h>

class RunTime
{
public:
	void start()
	{
		start_ = clock();
	}

	void stop()
	{
		finish_ = clock();
	}

	void show_run_time()
	{
		if (finish_ >= start_) {
			double total_time = (double)(finish_ - start_)/CLOCKS_PER_SEC;
			std::cout << total_time*1000 << "ms" << std::endl;
		}
	}

private:
	clock_t start_;
	clock_t finish_;
};

#endif