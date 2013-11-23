#include "QuickSort.h"

void CQuickSort::QuickSort(int A[], int left, int right)
{
	if(left < right)
	{
		int pivotIndex = m_partitioner.Partition(A, left, right);

		QuickSort(A, left, pivotIndex - 1);
		QuickSort(A, pivotIndex + 1, right);
	}
}

void CQuickSort::QuickSortIter(int A[], int left, int right)
{
	int pivotIndex; // the current partition value
	Stack<StateNode> recursionStack; // Stack which simulate the recursion

	CQuickSort::StateNode curr = {left, right};

	recursionStack.MakeEmpty();
	recursionStack.Push(curr);

	while (!recursionStack.IsEmpty())
	{
		curr = recursionStack.Pop();

		if (curr.left < curr.right)
		{
			pivotIndex = m_partitioner.Partition(A, curr.left, curr.right);
			CQuickSort::StateNode itemLeft = { curr.left, pivotIndex - 1 };
			recursionStack.Push(itemLeft);
			CQuickSort::StateNode itemRight = { pivotIndex + 1, curr.right };
			recursionStack.Push(itemRight);
		}
	}
}

void CQuickSort::SetPartitioner(Partitioner& newPartitioner)
{
	m_partitioner = newPartitioner;
}