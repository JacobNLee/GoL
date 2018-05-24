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

	PBM();
	~PBM();
};
