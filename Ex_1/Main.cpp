#include "CQuickSort.h"
#include <iostream>
using namespace std;

void main()
{
	try
	{
		CQuickSort& quickSorter = CQuickSort::GetInstance();

		int a[9] = { 1, 5, 3, 7, 9, 20, 1, 4, 0 };

		quickSorter.SortRecursive(a, 0, 8);

		for (int i = 0; i < 9; i++)
		{
			cout << a[i] << " ";
		}

		cin.ignore();
	}
	catch(...)
	{
		cerr << "An error occured while trying to sort.";
		cerr << "The program will end";
	}
}