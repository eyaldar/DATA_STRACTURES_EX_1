#include "LeftmostPivotPartitioner.h"

int LeftmostPivotPartitioner::Partition(int arr[], int left, int right)
{
	int middleIndex = ((right - left) / 2) + left;
	int leftIndex = left;
	int rightIndex = right;
	int pivotIndex = leftIndex;

	while(leftIndex < rightIndex)
	{
		// Whether the pivot is on the left side of array
		if(pivotIndex < middleIndex)
		{
			// Whether pivot is bigger than the current right element
			if (arr[pivotIndex] > arr[rightIndex])
			{
				Swap(arr, leftIndex++, rightIndex);
				pivotIndex = rightIndex;
			}
			else
			{
				rightIndex--;
			}
		}
		// the pivot is on the right side of array
		else
		{
			// Whether pivot is smaller than the current left element
			if (arr[leftIndex] > arr[pivotIndex])
			{
				Swap(arr, leftIndex, rightIndex--);
				pivotIndex = leftIndex;
			}
			else
			{
				leftIndex++;
			}
		}
	}

	return pivotIndex;
}