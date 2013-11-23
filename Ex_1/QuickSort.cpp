#include "QuickSort.h"

#include <iostream>

void QuickSort::SortRecursive(int arr[], int left, int right)
{
	if(left < right)
	{
		int pivotIndex = m_partitioner.Partition(arr, left, right);

		SortRecursive(arr, left, pivotIndex - 1);
		SortRecursive(arr, pivotIndex + 1, right);
	}
}

void QuickSort::SetPartitioner(Partitioner& newPartitioner)
{
	m_partitioner = newPartitioner;
}