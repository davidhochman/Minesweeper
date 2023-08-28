#pragma once
#include <random>

class Random {
	static std::mt19937 random;

public:
	static int randomNum(int min, int max);
};