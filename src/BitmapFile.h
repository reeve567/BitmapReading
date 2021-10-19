/**********************************************************
 * File:    bitmap_defs.h
 * Author:  Reeve Blake
 * Purpose: def of a bitmap file class
 *
 **********************************************************/
#include <fstream>
#include <string>
#include "bitmap_defs.h"

// Header guard
// *********************************************************
#ifndef BITMAPFILE_H
#define BITMAPFILE_H

class BitmapFile {
public:
	bool openFile(const std::string& file);

	template<typename T>
	int read(T &field);

private:
	std::ifstream bmFile;
};

#endif // BITMAPFILE_H
