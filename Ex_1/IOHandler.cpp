#include "IOHandler.h"

using namespace std;

void IOHandler::FillArray(ifstream& file, int size, int* arr) const
{
	int currNum;
	int inputNumIndex = 0;

	while (inputNumIndex < size && file >> currNum)
	{
		arr[inputNumIndex] = currNum;
		inputNumIndex++;
	}

	// If the number of input elements is smaller or bigger than size.
	if(size != inputNumIndex || file >> currNum)
		throw "Illegal input";
}

void IOHandler::PrintArray(ofstream& file, int size, const int arr[]) const
{
	file << size << endl;

	for (int i = 0; i < size; i++)
	{
		file << arr[i] << "   ";
	}
}