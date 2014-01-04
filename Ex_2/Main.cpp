// Main.cpp : main project file.

#include <iostream>
#include <fstream>

#include "TreeKey.h"
#include "TwoThreeTree.h"
#include "FileManager.h"

using namespace std;

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

// ==================================================================================
//
//		    Programming Exercise No. 2
//		    ===========================
//		Programmer:		Eyal Darshan
//		Identity no.:	200898435
//		Group:			Maof
//		Lecturer:		Iris Gaber
//
// ==================================================================================
void main()
{
	try
	{
		FileManager::GetInstance().OpenFile("input.txt", false);
		FileManager::GetInstance().OpenFile("output.txt", true);

		TwoThreeTree t;

		TreeKey key;
		string data;

		int dataNum = FileManager::GetInstance().ReadIntFromFile();

		for (int i = 0; i < dataNum; i++)
		{
			key = FileManager::GetInstance().ReadTreeKeyFromFile();
			data = FileManager::GetInstance().ReadStringFromFile();

			t.Insert(key, data);
		}

		TreeKey keyToDelete = FileManager::GetInstance().ReadTreeKeyFromFile();

		TreeNode* node = t.Find(keyToDelete);

		if(node != NULL)
		{
			t.Delete(keyToDelete);
		}
		else
		{
			FileManager::GetInstance().WriteStringToFile("Key does not exists");
			FileManager::GetInstance().WriteNewLine();
		}

		t.PrintData();
	}
	catch(const char* error)
	{
		cerr << "Error! " << error;

		FileManager::GetInstance().WriteStringToFile(error);
	}
	catch(...)
	{
		cerr << "Error!";
	}

	FileManager::GetInstance().CloseFile(true);
	FileManager::GetInstance().CloseFile(false);
}
