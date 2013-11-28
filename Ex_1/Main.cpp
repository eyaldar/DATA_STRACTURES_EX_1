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
//      1. Enter the required array size
//      2. Enter the elements
//
// ==================================================================================
void main()
{
	const string ILLEGAL_INPUT_STRING = "illegal input";

	int n;
	int* arr = NULL;

	CQuickSort& sorter = CQuickSort::GetInstance();

	try
	{
		cin >> n;

		if(n < 1)
			throw ILLEGAL_INPUT_STRING;
		
		arr = new int[n];

		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		
		sorter.QuickSort(arr, 0, n-1);

		cout << n;
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << "   ";
		}
	}
	catch (const string* error)
	{
		cerr << "Error: " << error;
	}
	catch (...)
	{
		cerr << endl << "An Error occured while sorting.";
		cerr << endl << "The program will end.";
	}

	delete[] arr;
}