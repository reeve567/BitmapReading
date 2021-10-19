/**********************************************************
 * File:    Pixel.h
 * Author:  Reeve Blake
 * Purpose: Implement pixel class
 *
 **********************************************************/

#include "Pixel.h"

// Constructors
// ****************************************************
Pixel::Pixel() {
	red = 0;
	green = 0;
	blue = 0;
}


Pixel::Pixel(BYTE red, BYTE green, BYTE blue) {
	this->red = red;
	this->blue = blue;
	this->green = green;
}

// Accessors
// ****************************************************

// Red
BYTE Pixel::getRed() {
	return red;
}


void Pixel::setRed(BYTE value) {
	red = value;
}


// Blue
BYTE Pixel::getBlue() {
	return blue;
}


void Pixel::setBlue(BYTE value) {
	blue = value;
}


// Green
BYTE Pixel::getGreen() {
	return green;
}


void Pixel::setGreen(BYTE value) {
	green = value;
}