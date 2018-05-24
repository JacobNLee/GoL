/*
/ Author: Jacob N. Lee
/ Project: Conway's Game of life with implemented image handling classes
/ Purpose: To implement custom image handling and have fun
/
/
/
/
/
*/

#include "Classes/netpbm.h"


int main()
{
	PBM pbm;
	pbm.loadImage("test.pbm");
	pbm.invert();
	pbm.saveImage("testInverted.pbm");


	return 0;
}