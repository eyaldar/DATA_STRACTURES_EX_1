#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

#include "Stack.h"
#include "LeftmostPivotPartitioner.h"

// Summary:
//		Represents an implementation of Quick Sort algorithm
//		in both recursive and iterative ways.
class CQuickSort {
public:

	// Summary:
	//		Gets the only instance of the CQuickSort class
	//
    // Returns:
    //		Returns the only instance of the CQuickSort class.
	static CQuickSort& GetInstance()
	{
		static CQuickSort instance;
		return instance;
	}

	// Summary:
	//		Replaces the default partitioner with another one
    //
    // Parameters:
    //   newPartitioner:
    //		a new partitioner to be used by this class.
	void SetPartitioner(Partitioner& newPartitioner);

    // Summary:
	//		Sorts an array of elements according to the Quick Sort algorithm in a recursive way
    //
    // Parameters:
    //   arr[]:
    //		An array of elements to sort.
	//   left:
    //		The left end position to sort from.
	//   right:
    //		The right end position to sort to.
	void QuickSort(int A[], int left, int right);

	// Summary:
	//		Sorts an array of elements according to the Quick Sort algorithm in a iterative way
    //
    // Parameters:
    //	 arr[]:
    //		An array of elements to sort.
	//   left:
    //		The left end position to sort from.
	//   right:
    //		The right end position to sort to.
	void QuickSortIter(int A[], int left, int right);

private:
	Partitioner& m_partitioner; // Used to perform the Partition phase of the Quick Sort algorithm

	// Summary:
	//		A private constructor for the CQuickSort class
	//		By default uses a Leftmost element as pivot.
	CQuickSort() 
	: m_partitioner(LeftmostPivotPartitioner::GetInstance()) {}

	// Summary:
	//		A private destructor for the CQuickSort class
	~CQuickSort() {}

	//		Represent one iteration of iterative QucikSort for the stack.
	struct StateNode{
	public:
		int left;
		int right;
	};
};

#endif