#include "LeftmostPivotPartitioner.h"

int LeftmostPivotPartitioner::Partition(int arr[], int left, int right)
{
	// Determine whether the pivot is on the left side - starts as true
	bool isPivotOnLeft = true;
	int pivotIndex = left;

	while(left < right)
	{
		// Whether the pivot is on the left side of array
		if(isPivotOnLeft)
		{
			// Whether pivot is bigger than the current right element
			if (arr[pivotIndex] > arr[right])
			{
				Swap(arr, left++, right);
				pivotIndex = right;

				// Moves pivot to the right side
				isPivotOnLeft = !isPivotOnLeft;
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

				// Moves pivot to the left side
				isPivotOnLeft = !isPivotOnLeft;
			}
			else
			{
				left++;
			}
		}
	}

	return pivotIndex;
}