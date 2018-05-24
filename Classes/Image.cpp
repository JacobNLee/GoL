#include "Image.h"


uint Image::getHeight()
{
	return height;
}

uint Image::getWidth()
{
	return width;
}

Image::Image()
{
	//height = 0; 
	//width  = 0;
}
Image::Image( int newHeight, int newWidth )
{
	if( newHeight >= 0 && newWidth >= 0)
	{
		height = (uint) newHeight;
		width  = (uint) newWidth;
	}
	else
	{
		throw std::runtime_error("Tried to create an image with a negative dimension size");
	}
}

Image::~Image()
{
	
}