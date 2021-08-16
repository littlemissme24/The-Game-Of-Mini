#include "Tool.h"
#include <stdlib.h>
#include <ctime>
#include <stdio.h>
#include <chrono>

int Tool::RNG(int high, int low)
{
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	srand(time(NULL));
	return rand() % (high + low);
}

int Tool::RNG()
{
	return 0;
}
