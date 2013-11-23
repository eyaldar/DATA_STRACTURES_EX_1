#include "Partitioner.h"

void Partitioner::Swap(int& firstVal, int& secondVal)
{
	int temp = firstVal;
	firstVal = secondVal;
	secondVal = temp;
}

void Partitioner::Swap(int arr[], int firstIndex, int secondIndex)
{
	Swap(arr[firstIndex], arr[secondIndex]);
}