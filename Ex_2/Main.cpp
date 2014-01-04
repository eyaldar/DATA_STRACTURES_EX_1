// Main.cpp : main project file.

#include <iostream>
#include <fstream>

#include "TreeKey.h"
#include "TwoThreeTree.h"

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
		TwoThreeTree t;

		t.Insert(2, "a");

		t.Insert(5, "b");

		t.Insert(6, "c");

		t.Insert(7, "d");

		t.Insert(8, "e");

		t.Insert(12, "f");

		t.Insert(16, "g");

		t.Insert(19, "h");

		t.Insert(4, "j");

		t.PrintKeys();

		t.Delete(12);

		t.PrintKeys();
	}
	catch(const char* error)
	{
		cerr << "Error! " << error;
	}
	catch(...)
	{
		cerr << "Error!";
	}
}
