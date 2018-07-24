#include "bmpfunc.h"

#ifndef FUNC_GIVEN

int RGB2Gray(unsigned char red, unsigned char green, unsigned char blue)
{
	// This is a commonly used formula
	double gray = 0.2989 * red + 0.5870 * green + 0.1140 * blue;
	return (int) gray;
}

#endif


#ifndef IMG_TO_GRAY

BMPImage * ImgToGray(BMPImage * img)
{
	// Convert color image to grayscale
	// BONUS for HW08
	return NULL;
}

#endif


#ifndef HIST_EQ

BMPImage * HistogramEqualization(BMPImage * grayImage)
{
	// Takes the input as a grayscale image
	// Output is equalized image
	// BONUS for HW08
	return NULL;

}


#endif
