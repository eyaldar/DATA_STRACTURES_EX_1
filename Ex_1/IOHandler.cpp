#include "IOHandler.h"

using namespace std;

void IOHandler::ReadArray(std::ifstream& file, int& size, int*& arr) const
{
	file >> size;

	if(size < 1)
		throw "Illegal input";
		
	int currNum;
	arr = new int[size];

	int inputNumIndex = 0;

	while (file >> currNum && inputNumIndex < size)
	{
		arr[inputNumIndex] = currNum;
		inputNumIndex++;
	}

	// If the number of input elements is smaller or bigger than size.
	if(size != inputNumIndex || file >> currNum)
		throw "Illegal input";
}
void IOHandler::PrintArray(std::ofstream& file, int size, const int arr[]) const
{
	file << size << endl;

	for (int i = 0; i < size; i++)
	{
		file << arr[i] << "   ";
	}
}