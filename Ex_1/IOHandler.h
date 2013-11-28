#ifndef __IO_HANDLER_H__
#define __IO_HANDLER_H__

#include <fstream>

// Summary:
//		Used to implement I/O operations for this application.
class IOHandler{
public:

	// Summary:
	//		Gets the only instance of the IOHandler class
	//
    // Returns:
    //		Returns the only instance of the IOHandler class.
	static const IOHandler& GetInstance()
	{
		static IOHandler instance;
		return instance;
	}

	// Summary:
	//		Read array size and array data from a file stream.
    //
    // Parameters:
    //   file:
    //		The stream to read from.
	//   size:
    //		The size of the array we read from the file.
	//   arr:
    //		Pointer to array that this method creates.
	//
	// Execptions:
	//		throws an exception in case the number of data element is different from the given array size.
	//		or in case the array size is invalid.
	//
	// Note: 
	//		it is the user's responsibility to free the created array.
	//
	void IOHandler::ReadArray(std::ifstream& file, int& size, int*& arr) const;

	// Summary:
	//		Prints an array to a file stream.
    //
    // Parameters:
    //   file:
    //		The stream to print into.
	//   size:
    //		The size of the array
	//   arr:
    //		The array to print.
	void PrintArray(std::ofstream& file, int size, const int arr[]) const;

private:

	// Summary:
	//		A private constructor for the IOHandler class
	IOHandler() {}
};

#endif