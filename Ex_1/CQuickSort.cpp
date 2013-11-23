#include "CQuickSort.h"

void CQuickSort::SortRecursive(int arr[], int left, int right)
{
	if(left < right)
	{
		int pivotIndex = partitioner->Partition(arr, left, right);

		SortRecursive(arr, 0, pivotIndex - 1);
		SortRecursive(arr, pivotIndex + 1, right);
	}
}

void CQuickSort::SetPartitioner(Partitioner* newPartitioner)
{
	partitioner = newPartitioner;
}