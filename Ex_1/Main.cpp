// DsEx1QuickSort.cpp : main project file.

#include "QuickSort.h"

#include <iostream>
using namespace std;

// ==================================================================================
//
//		    Programming Exercise No. 1
//		    ===========================
//		Programmer:		Eyal Darshan
//		Identity no.:	200898435
//		Group:			Maof
//		Lecturer:		Iris Gaber
//
// ==================================================================================
//
//	  	    Program Instructions:
//		    =====================
//      1. Enter 5 numbers to sort.
//      2. Enter lower and higher bounds in which the array should be sorted.
//      3. Enter requested sort method: recursive (=0) or non-recursive (=1).
//      4. The unsorted array and the sorted array will be printed.
//      5. If you want to make another sort, enter Yes (=1). Otherwise, enter no (=0).
//		6. Note: The size of the array to sort is set by the const ARR_SIZE.
//               you can change its value here if you want to sort a bigger array.
//
// ==================================================================================
void main()
{
	const int ARR_SIZE = 5;

	int A[ARR_SIZE];
	int shouldContinueLoop;

	CQuickSort& sorter = CQuickSort::GetInstance();

	try
	{
		do
		{
			// Getting the array from the user
			cout << endl << endl <<  "Enter " << ARR_SIZE << " numbers to sort: ";
			for (int i = 0; i < ARR_SIZE; i++)
			{
				cin >> A[i];
			}

			// Getting the bounds in which the array should be sorted from the user
			bool areBoundsLegal = false;
			int left, right;
			cout << endl << "Enter lower bound (between 0 and " << (ARR_SIZE - 1) << "): ";
			cin >> left;
			cout << endl << "Enter higher bound (between 0 and " << (ARR_SIZE - 1) << "): ";
			cin >> right;

			if (right < left || right >= ARR_SIZE || left >= ARR_SIZE || left < 0 || right < 0)
			{
				cout << endl << endl << "Illegal Bounds!";
				cin.ignore();
			}
			else
			{
				// Getting the requested sort method from the user
				cout << endl << "Enter 0 for Recursive Quick Sort, 1 for Non Recursive: ";
				int intSortType;
				cin >> intSortType;

				// Printing the unsorted array
				cout << endl << endl << "Before Sort:";
				for (int i = 0; i < ARR_SIZE; i++)
					cout << "\t" << A[i];

				// Sorting the array
				if (intSortType == 0)
					sorter.QuickSort(A, left, right);
				else
					sorter.QuickSortIter(A, left, right);

				// Printing the sorted array
				cout << endl << "After Sort:";
				for (int i = 0; i < ARR_SIZE; i++)
					cout << "\t" <<  A[i];
			}

			// Asking the user if he wants to do another sort
			shouldContinueLoop = 0;
			cout << endl << endl << "Do you want to continue sorting? (Enter 0 for NO, 1 for YES): ";
			cin >> shouldContinueLoop;

		} while(shouldContinueLoop);	// Sorting until the user askes to stop
	}
	catch (...)
	{
		cout << endl << "An Error occured while sorting.";
		cout << endl << "The program will end.";

		cin.ignore();
	}
}