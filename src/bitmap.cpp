/**********************************************************
 * File:    bitmap.cpp
 * Author:  Reeve Blake
 * Purpose: Read headers of a bitmap file
 *
 **********************************************************/
#include <iostream>
#include <string>
#include "BitmapFile.h"

// start main
// *********************************************************
int main() {
	std::string fileName;

	std::cout << "Bitmap bitmapFile name: ";
	std::cin >> fileName;

	BitmapFile bitmapFile;

	if (!bitmapFile.openFile(fileName)) {
		std::cout << "Couldn't open file " << fileName << "!\n";
		return 1;
	}
	std::cout << "File opened!\n";

	return 0;
} // end main