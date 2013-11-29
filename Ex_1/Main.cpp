// DsEx1QuickSort.cpp : main project file.

#include "QuickSort.h"
#include "IOHandler.h"

#include <iostream>
#include <fstream>
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
	int arrSize;
	int *arr = NULL;
	int	*arrIter = NULL;

	CQuickSort& sorter = CQuickSort::GetInstance();
	const IOHandler& ioHandler = IOHandler::GetInstance();

	try
	{
		ifstream inputFile;
		inputFile.open("input.txt");

		// Read array size.
		inputFile >> arrSize;

		// Throws in case the array size is invalid.
		if(arrSize < 1)
			throw "Illegal input";

		// Create the array and fill with data
		arr = new int[arrSize];
		ioHandler.FillArray(inputFile, arrSize, arr);
		
		// copy the arr to another array.
		arrIter = new int[arrSize];

		for (int i = 0; i < arrSize; i++)
		{
			arrIter[i] = arr[i];
		}

		inputFile.close();

		sorter.QuickSortIter(arr, 0, arrSize-1);
		sorter.QuickSortIter(arrIter, 0, arrSize-1);

		ofstream outputFile;
		outputFile.open("output.txt");

		ioHandler.PrintArray(outputFile, arrSize, arr);
		outputFile << endl;
		ioHandler.PrintArray(outputFile, arrSize, arrIter);
	}
	catch (...)
	{
		cerr << "Error : illegal input";
		cin.ignore();
	}

	delete[] arr;
	delete[] arrIter;
}