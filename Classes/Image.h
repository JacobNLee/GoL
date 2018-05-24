typedef unsigned int uint;


#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

//Base Class
class Image
{
	private:
		int nice;
	protected:
		int width;
		int height;
		

		std::string comments;

		std::ifstream fin;
		std::ofstream fout;

	public:
		uint getHeight();
		uint getWidth();

		virtual bool loadImage( std::string )=0;
		virtual bool saveImage( std::string )=0;

		virtual void invert()=0;

		//Constructors
		Image();
		Image(int inHeight, int inWidth);
		~Image();


};
