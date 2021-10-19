/**********************************************************
 * File:    bitmap_defs.h
 * Author:  Reeve Blake
 * Purpose: def of a bitmap file class
 *
 **********************************************************/
#include <string>
#include <fstream>
#include "BitmapFile.h"

/**
 * Open the file from a stream
 * @param file - the path to the file to open
 * @return bool - whether or not the file was opened
 */
bool BitmapFile::openFile(const std::string& file) {
	bmFile.open(file, std::ios::binary);
	return bmFile.is_open();
}

/**
 * Reads byes from the file stream
 * @tparam T - The type of the field, determines how much space to use
 * @param bmFile - The file stream
 * @param field - Fill from file stream
 * @return int - number of bytes read
 */
template<typename T>
int BitmapFile::read(T &field) {
	int sizeRead = sizeof(T);

	bmFile.read(reinterpret_cast<char *>(&field), sizeRead);

	return sizeRead;
}