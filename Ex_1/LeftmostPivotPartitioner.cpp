#include "LeftmostPivotPartitioner.h"

int LeftmostPivotPartitioner::Partition(int arr[], int left, int right)
{
	int middleIndex = ((right - left) / 2);
	int pivotIndex = left;
	int rightIndex = right;

	while(pivotIndex < rightIndex)
	{
		if(pivotIndex < middleIndex)
		{
			if (arr[pivotIndex] > arr[rightIndex])
			{
				Swap(arr, pivotIndex, rightIndex);
				pivotIndex++;
			}
			else
			{
				rightIndex--;
			}
		}
		else
		{
			if (arr[pivotIndex] > arr[rightIndex])
			{
				Swap(arr, pivotIndex, rightIndex);
				rightIndex--;
			}
			else
			{
				pivotIndex++;
			}
		}
	}

	return pivotIndex;
}