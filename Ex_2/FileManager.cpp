#include "FileManager.h"

#include <string>

void FileManager::OpenFile(const std::string& filename, bool forOutput)
{
	if(forOutput)
    {
        outputFile.open(filename, ios_base::out);

		if(!outputFile)
		{
			throw "File not found";
		}
    }
    else
    {
        inputFile.open(filename, ios_base::in);

		if(!inputFile)
		{
			throw "Problem accured trying to open the file";
		}
    }
}

void FileManager::CloseFile(bool forOutput)
{
	if(forOutput)
    {
        outputFile.close();
    }
    else
    {
        inputFile.close();
    }
}

void FileManager::WriteStringToFile(const string& dataToWrite) 
{
	outputFile << dataToWrite;
	outputFile << " ";
}

string FileManager::ReadStringFromFile()
{
	string str;
	inputFile >> str;

	return (str);
}

void FileManager::WriteTreeKeyToFile(TreeKey dataToWrite) 
{
	outputFile << dataToWrite;
	outputFile << " ";
}

int FileManager::ReadIntFromFile()
{
	TreeKey nNumber;
	inputFile >> nNumber;

	return (nNumber);
}

void FileManager::WriteNewLine()
{
	outputFile << endl;
}

TreeKey FileManager::ReadTreeKeyFromFile()
{
	TreeKey key;
	inputFile >> key;

	return (key);
}
