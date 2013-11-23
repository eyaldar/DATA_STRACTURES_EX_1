#include "LeftmostPivotPartitioner.h"

int LeftmostPivotPartitioner::Partition(int arr[], int left, int right)
{
	int middleIndex = ((right - left) / 2) + left;
	int pivotIndex = left;

	while(left < right)
	{
		// Whether the pivot is on the left side of array
		if(pivotIndex < middleIndex)
		{
			// Whether pivot is bigger than the current right element
			if (arr[pivotIndex] > arr[right])
			{
				Swap(arr, left++, right);
				pivotIndex = right;
			}
			else
			{
				right--;
			}
		}
		// the pivot is on the right side of array
		else
		{
			// Whether pivot is smaller than the current left element
			if (arr[left] > arr[pivotIndex])
			{
				Swap(arr, left, right--);
				pivotIndex = left;
			}
			else
			{
				left++;
			}
		}
	}

	return pivotIndex;
}