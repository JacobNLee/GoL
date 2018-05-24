#include "netpbm.h"

bool PBM::loadImage( std::string loadFrom )
{
	

	fin.open( loadFrom.c_str() );

	readImageHeader();
	deleteImageData();
	imageData = allocateImageData();
	readImageData();

	fin.close();
	return true;


	
}

bool PBM::saveImage( std::string saveTo )
{	
	fout.open( saveTo.c_str() );

	writeImage();

	fout.close();

	return true;
}

void PBM::invert()
{
	int rIndex, cIndex;

	for( rIndex = 0; rIndex < height; ++rIndex )
	{
		for( cIndex = 0; cIndex < width; ++cIndex )
		{
			if( imageData[ rIndex ][ cIndex ] == (char) 0 )
			{
				imageData[ rIndex ][ cIndex ] = (char) 1;
			}
			else
			{
				imageData[ rIndex ][ cIndex ] = (char) 0;
			}
		}

	}
}

PBM::PBM()
{
	imageData = NULL;
}

PBM::~PBM()
{
	deleteImageData();
}

bool PBM::readImageHeader()
{
	int temp;
	std::string tempString;
	//check to see if file is open

	fin >> tempString;

	//Checks if the file is of PBM
	if( tempString != "P1")
	{
		return false;
	}

	
	if( fin.peek() == (int) '#' )
	{
		std::getline(fin, comments);
	}
	
	fin >> width;
	fin >> height;

	return true;
	
}

void PBM::newImage(int newWidth, int newHeight)
{
	deleteImageData();

	width  = newWidth;
	height = newHeight;

	imageData = allocateImageData();
	fillImage( 0 );
}

void PBM::fillImage( char fillWith )
{
	int rIndex, cIndex;

	for( rIndex = 0; rIndex < height; ++rIndex )
	{	
		for( cIndex = 0; cIndex < width; ++cIndex )
		{
			imageData[ rIndex ][ cIndex ] = (char) fillWith;
		}
	}
}

char** PBM::allocateImageData()
{
	int index;
	char** newImageData;
	newImageData = new char*[ height ];
	for( index = 0; index < height; ++index )
	{
		newImageData[ index ] = new char[ width ];
	}

	return newImageData;
}

void PBM::deleteImage()
{
	deleteImageData();
	width = height = 0;
}

void PBM::deleteImageData()
{
	if( !isEmpty() )
	{
		int index;

		for( index = 0; index < height; ++index )
		{
			delete [] imageData[ index ];
		}
		delete [] imageData;
		imageData = NULL;
	}

}

bool PBM::isEmpty()
{
	if( imageData == NULL )
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PBM::readImageData()
{
	int rIndex, cIndex;
	int temp;

	for( rIndex = 0; rIndex < height; ++rIndex )
	{
		
		for( cIndex = 0; cIndex < width; ++cIndex )
		{
			fin >> temp;
			imageData[ rIndex ][ cIndex ] = (char) temp;
		}

	}
}

void PBM::writeImage()
{
	int rIndex, cIndex;

	fout << "P1" << std::endl;
	fout << width << ' ' << height << std::endl;

	for( rIndex = 0; rIndex < height; ++rIndex )
	{
		for( cIndex = 0; cIndex < width; ++cIndex )
		{
			fout << (int) imageData[ rIndex ][ cIndex ] << ' ';
		}
		fout << std::endl;
	}
}


void PBM::upscale()
{
	int rIndex, cIndex, index;
	char** oldImageData = imageData;

	width  = width * 2;
	height = height * 2;
	imageData = allocateImageData();
	
	for( rIndex = 0; rIndex < height; ++rIndex )
	{
		for( cIndex = 0; cIndex < width; ++cIndex )
		{
			imageData[ rIndex ][ cIndex ] = oldImageData[ rIndex / 2][ cIndex / 2 ];
		}
	}


	for( index = 0; index < height/2; ++index )
	{
		delete [] oldImageData[ index ];
	}
	delete [] oldImageData;
	oldImageData = NULL;
	
}

void PBM::downscale()
{
	int rIndex, cIndex, index;
	char** oldImageData = imageData;

	width  = width / 2;
	height = height / 2;
	imageData = allocateImageData();

	
	for( rIndex = 0; rIndex < height; ++rIndex )
	{
		for( cIndex = 0; cIndex < width; ++cIndex )
		{
			//maybe add a mask to average the downscaling
			imageData[ rIndex ][ cIndex ] = oldImageData[ rIndex * 2][ cIndex * 2 ];
		}
	}

	for( index = 0; index < height/2; ++index )
	{
		delete [] oldImageData[ index ];
	}
	delete [] oldImageData;
	oldImageData = NULL;
}