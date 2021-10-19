/**********************************************************
 * File:    Pixel.h
 * Author:  Reeve Blake
 * Purpose: Define pixel class
 *
 **********************************************************/
#include "bitmap_defs.h"

#ifndef PIXEL_H
#define PIXEL_H


class Pixel {
public:
	// Constructors
	// ****************************************************
	Pixel();
	Pixel(BYTE red, BYTE green, BYTE blue);

	// Accessors
	// ****************************************************
	BYTE getRed();
	void setRed(BYTE value);

	BYTE getBlue();
	void setBlue(BYTE value);

	BYTE getGreen();
	void setGreen(BYTE value);

	// Member methods
	// ****************************************************
private:
	BYTE red;
	BYTE green;
	BYTE blue;
};


#endif // PIXEL_H
