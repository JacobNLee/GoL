#include "Image.h"


class PBM: public Image
{
	private:
	char** imageData;

	bool readImageHeader();

	char** allocateImageData();
	void deleteImageData();
	void readImageData();

	void writeImage();

	public:
	bool loadImage( std::string );
	bool saveImage( std::string );

	void invert();

	void deleteImage();
	void newImage(int newWidth, int newHeight);

	void rotate90(int rotations);
	void upscale();
	void downscale();

	void fillImage( char fillwith );

	bool isEmpty();

	//copy constructor
	//overload equals
	//overload [] or ()
	PBM();
	~PBM();
};
