/**********************************************************
 * File:    bitmap.cpp
 * Author:  Reeve Blake
 * Purpose: Read headers of a bitmap file
 *
 **********************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

// Global defines
// *********************************************************

// data type sizes for data structures
#define BYTE  uint8_t   // 1 byte
#define WORD  uint16_t  // 2 bytes
#define DWORD uint32_t  // 4 bytes

struct BMFileHeader {
	BYTE bitmapType[2];
	DWORD fileSize;
	WORD reserved1;
	WORD reserved2;
	DWORD offset;

};

struct BMInfoHeader {
	DWORD headerSize;
	DWORD bitmapWidth;
	DWORD bitmapHeight;
	WORD colorPlanes;
	WORD colorDepth;
	DWORD compressionMethod;
	DWORD imageSize;
	DWORD horizontalResolution;
	DWORD verticalResolution;
	DWORD colorPaletteSize;
	DWORD importantColorsSize;
};

struct Pixel {
	BYTE red;
	BYTE green;
	BYTE blue;
};

// Function prototypes
// *********************************************************

template<typename T>
int read(std::ifstream &bmFile, T &field);

// Main
// *********************************************************
int main() {
	std::string fileName = "../bitmap.bmp";

	std::ifstream file;

	int bytesRead = 0;

	file.open(fileName, std::ios::binary);

	// load file header
	BMFileHeader bmFileHeader{};

	bytesRead += read(file, bmFileHeader.bitmapType[0]);
	bytesRead += read(file, bmFileHeader.bitmapType[1]);
	bytesRead += read(file, bmFileHeader.fileSize);
	bytesRead += read(file, bmFileHeader.reserved1);
	bytesRead += read(file, bmFileHeader.reserved2);
	bytesRead += read(file, bmFileHeader.offset);

	// load info header
	BMInfoHeader bmInfoHeader{};

	bytesRead += read(file, bmInfoHeader.headerSize);
	bytesRead += read(file, bmInfoHeader.bitmapWidth);
	bytesRead += read(file, bmInfoHeader.bitmapHeight);
	bytesRead += read(file, bmInfoHeader.colorPlanes);
	bytesRead += read(file, bmInfoHeader.colorDepth);
	bytesRead += read(file, bmInfoHeader.compressionMethod);
	bytesRead += read(file, bmInfoHeader.imageSize);
	bytesRead += read(file, bmInfoHeader.horizontalResolution);
	bytesRead += read(file, bmInfoHeader.verticalResolution);
	bytesRead += read(file, bmInfoHeader.colorPaletteSize);
	bytesRead += read(file, bmInfoHeader.importantColorsSize);

	std::cout << "File type             : " << bmFileHeader.bitmapType[0] << bmFileHeader.bitmapType[1] << std::endl;
	std::cout << "File size             : " << bmFileHeader.fileSize << std::endl;
	std::cout << "Pixel offset          : " << bmFileHeader.offset << std::endl;
	std::cout << std::endl;
	std::cout << "Header size           : " << bmInfoHeader.headerSize << std::endl;
	std::cout << "Bitmap Width          : " << bmInfoHeader.bitmapWidth << std::endl;
	std::cout << "Bitmap Height         : " << bmInfoHeader.bitmapHeight << std::endl;
	std::cout << "Color Planes          : " << bmInfoHeader.colorPlanes << std::endl;
	std::cout << "Color Depth           : " << bmInfoHeader.colorDepth << std::endl;
	std::cout << "Compression Method    : " << bmInfoHeader.compressionMethod << std::endl;
	std::cout << "Image Size            : " << bmInfoHeader.imageSize << std::endl;
	std::cout << "Horizontal Resolution : " << bmInfoHeader.horizontalResolution << std::endl;
	std::cout << "Vertical Resolution   : " << bmInfoHeader.verticalResolution << std::endl;
	std::cout << "Color Palette Size    : " << bmInfoHeader.colorPaletteSize << std::endl;
	std::cout << "Important Color Size  : " << bmInfoHeader.importantColorsSize << std::endl;

	// store remaining bytes between info header and pixel array

	BYTE *gap1;
	unsigned int gap1Size = bmFileHeader.offset - bytesRead;

	if (gap1Size) {
		gap1 = new BYTE[gap1Size];
		for (int next = 0; next < gap1Size; next++) {
			bytesRead += read(file, gap1[next]);
		}
	} // gap 1 exists

	// cmath
	// floor function
	int rowSize = (int) floor((bmInfoHeader.colorDepth * bmInfoHeader.bitmapWidth + 31) / 32) * 4;

	auto **pixels = new Pixel*[bmInfoHeader.bitmapHeight];

	for (int row = 0; row < bmInfoHeader.bitmapHeight; row++) {
		pixels[row] = new Pixel[bmInfoHeader.bitmapWidth];

		int rowBytesRead = 0;
		for (int column = 0; column < bmInfoHeader.bitmapWidth; column++) {
			Pixel pixel = { 0 };

			rowBytesRead += read(file, pixel.blue);
			rowBytesRead += read(file, pixel.green);
			rowBytesRead += read(file, pixel.red);

			pixels[row][column] = pixel;
		} // for each column

		int padding = rowSize - rowBytesRead;

		for (int pad = 0; pad < padding; pad++) {
			BYTE scratch;
			rowBytesRead += read(file, scratch);
		}

		bytesRead += rowBytesRead;
	} // for each row

	return 0;
} // end main
