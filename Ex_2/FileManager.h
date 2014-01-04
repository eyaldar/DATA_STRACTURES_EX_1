#ifndef __FILE_MANAGER_H__
#define __FILE_MANAGER_H__

#include <iostream>
#include <fstream>

#include "TreeKey.h"
#include "FileManager.h"

using namespace std;

class FileManager {

private:
    FileManager() {}
	ofstream outputFile;
	ifstream inputFile;

public:
    static FileManager& GetInstance()
    {
            static FileManager instance;
            return instance;
    }
	void OpenFile(const std::string& filename, bool forOutput);
	void CloseFile(bool forOutput);

	void WriteNewLine();
    void WriteStringToFile(const std::string&);
	void WriteTreeKeyToFile(TreeKey);
    const std::string ReadStringFromFile();
	TreeKey ReadTreeKeyFromFile();
	int ReadIntFromFile();
};

#endif