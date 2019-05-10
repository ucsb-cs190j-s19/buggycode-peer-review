#include "arrayFuncs.h"
#include <cstdlib>
#include <iostream>

#include "utility.h"

bool isOdd(int a);


int sumOdds(int a[], int size) {
	
	if(size < 1)
	{
		std::cerr << "Wrong size" << std::endl;
		exit(1);
	}
	
	int sumOfOdds = 0;

	for(int i = 0; i < size; i++)
	{
		if(isOdd(a[i]))
			sumOfOdds += a[i];
	}
	
	return sumOfOdds;
}
