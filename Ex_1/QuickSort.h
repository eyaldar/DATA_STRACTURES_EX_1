#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

#include "LeftmostPivotPartitioner.h"

// Summary:
//		Represents an implementation of Quick Sort algorithm
//		in both recursive and iterative ways.
class QuickSort {
public:
	// Summary:
	//		Gets the only instance of the CQuickSort class
	//
    // Returns:
    //		Returns the only instance of the CQuickSort class.
	static QuickSort& GetInstance()
	{
		static QuickSort instance;
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
	void SortRecursive(int arr[], int left, int right);

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
	void SortIterative(int arr[], int left, int right);

private:
	Partitioner& m_partitioner; // Used to perform the Partition phase of the Quick Sort algorithm

	// Summary:
	//		A private constructor for the CQuickSort class
	//		By default uses a Leftmost element as pivot.
	QuickSort() 
	: m_partitioner(LeftmostPivotPartitioner::GetInstance()) {}

	// Summary:
	//		A private destructor for the CQuickSort class
	~QuickSort() {}
};

#endif