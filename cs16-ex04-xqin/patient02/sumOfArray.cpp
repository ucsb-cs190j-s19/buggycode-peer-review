#include "arrayFuncs.h"

int sumOfArray(int a[], int size) {

	if(size < 1)
	{
		std::cerr << "Array less than 1" << std::endl;
		exit(1);
	}

	int sumArray = 0;

	for(int i = 0; i < size; i++)
	{
		sumArray += a[i];
	}

	return sumArray;
}
