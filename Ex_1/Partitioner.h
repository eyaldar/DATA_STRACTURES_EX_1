#ifndef __PARTITIONER_H__
#define __PARTITIONER_H__

// Summary:
//		Represents a base implemention for all quick sort partition logic implementations
class Partitioner{
public:
    // Summary:
	//		Chooses a pivot and puts it in the right place in the array 
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
	virtual int Partition(int arr[], int left, int right) abstract;

protected:
	// Summary:
	//		Swaps two elements' values sent by reference.
    //
    // Parameters:
	//   firstVal:
    //		The first value to swap.
	//   secondVal:
    //		the second value to swap.
	void Swap(int& firstVal, int& secondVal);

	// Summary:
	//		Swaps two values' position in an array of values.
    //
    // Parameters:
    //   arr[]:
    //		An array of elements.
	//   firstIndex:
    //		The first value's index inside the array.
	//   secondIndex:
    //		The second value's index inside the array.
	void Swap(int arr[], int firstIndex, int secondIndex);
};

#endif