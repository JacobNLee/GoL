#include "Image.h"


class PBM: public Image
{
	private:
	char** imageData;

	bool readImageHeader();

	void allocateImageData();
	void deleteImageData();
	void readImageData();

	void writeImage();

	public:
	bool loadImage( std::string );
	bool saveImage( std::string );

	void invert();

	void deleteImage();
	void newImage();

	void rotate90(int rotations);
	void upscale(int factor);
	void downscale(int factor);

	//copy constructor
	//overload equals
	//overload [] or ()
	PBM();
	~PBM();
};
