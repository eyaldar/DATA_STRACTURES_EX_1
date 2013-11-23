#ifndef __LEFTMOST_PIVOT_PARTITIONER_H__
#define __LEFTMOST_PIVOT_PARTITIONER_H__

#include "Partitioner.h"

// Summary:
//		Represents an implemention of Quick Sort algorithm's partition,
//      Chooses the leftmost index as pivot
class LeftmostPivotPartitioner : public Partitioner{
public:
	// Summary:
	//		Gets the only instance of the CQuickSort class
    // Returns:
    //		Returns the only instance of the CQuickSort class.
	static LeftmostPivotPartitioner& GetInstance()
	{
		static LeftmostPivotPartitioner instance;
		return instance;
	}

	// Summary:
	//		Chooses the leftmost element as pivot and puts it in the right place in the array 
	//      (where it whould have been if the array was sorted in ascending order),
	//		all the smaller values left to the pivot (unordered) and all the bigger values right to it.
	//
    // Parameters:
    //   arr[]:
    //		An array of elements to partition.
	//   left:
    //		The left end position to partition from.
	//   right:
    //		The right end position to partition to.
	//
	// Returns:
    //		Returns the chosen pivot's index.
	//
	// Exceptions:
	//		The method will throw an exception in the following cases:
	//		1. The array was not initialized
	//		2. left or right are out of bounds for the given array
	virtual int Partition(int arr[], int left, int right) override;

private:
	// Summary:
	//		A private constructor for the LeftmostPivotPartitioner class
	LeftmostPivotPartitioner() 
	{
	}

	// Summary:
	//		A private destructor for the LeftmostPivotPartitioner class
	~LeftmostPivotPartitioner() {}
};

#endif