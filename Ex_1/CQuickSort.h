#ifndef __CQUICK_SORT_H__
#define __CQUICK_SORT_H__

#include "LeftmostPivotPartitioner.h"

// Summary:
//		Represents an implementation of Quick Sort algorithm
//		in both recursive and iterative ways.
class CQuickSort {
public:
	// Summary:
	//		Gets the only instance of the CQuickSort class
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
	//
	// Notes:
	//		Any given partitioner will be released automatically by the class 
	//		when that partitioner is replaced or when the class is destructed
	void SetPartitioner(Partitioner* newPartitioner);

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
	//
	// Exceptions:
	//		The method will throw an exception in the following cases:
	//		1. The array was not initialized
	//		2. left or right are out of bounds for the given array
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
	//
	// Exceptions:
	//		The method will throw an exception in the following cases:
	//		1. The array was not initialized
	//		2. left or right are out of bounds for the given array
	//void SortIterative(int arr[], int left, int right);

private:
	Partitioner* partitioner;

	// Summary:
	//		A private constructor for the CQuickSort class
	CQuickSort() 
	{
		partitioner = &LeftmostPivotPartitioner::GetInstance();
	}

	// Summary:
	//		A private destructor for the CQuickSort class
	~CQuickSort() {}
};

#endif