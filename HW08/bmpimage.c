#include "bmpimage.h"

/* check whether a header is valid
 * assume that header has been read from fptr
 * the position of the indicator of fptr is not certain
 * could be at the beginning of the file, end of the file or
 * anywhere in the file
 * note that the check is only for this exercise/assignment
 * in general, the format is more complicated
 */

#ifndef HEADER_VALID

int Is_BMPHeader_Valid(BMPHeader* header) 
{
	// Make sure this is a BMP file
	// skip the two unused reserved fields

	// check the BMP header

	// check the header type == MAGICVALUE
	// For this exercise
	// Make sure there is only one image plane
	// Make sure there is no compression

	// skip the test for xresolution, yresolution

	// Make sure we are getting 24 bits per pixel
	// only for this assignment

	return 0;

}

#endif



#ifndef BMP_OPEN_FILE
/* The input argument is the source file pointer.
 * The function returns an address to a dynamically allocated BMPImage
 * only if the file contains a valid image file
 * Otherwise, return NULL
 * If the function cannot get the necessary memory to store the image,
 * also return NULL
 * Any error messages should be printed to stderr
 */


BMPImage *BMP_Open(const char *filename)
{
	// Open file 	
	// Allocate memory for BMPImage*;

	// Read the first 54 bytes of the source into the header


	// Compute data size, width, height, and bytes per pixel;


	// Allocate memory for image data


	// Read in the image data
	return NULL;

}

#endif


#ifndef BMP_WRITE_FUNC
/* The input arguments are the destination file , BMPImage *image.
 * The function write the header and image data into the destination file.
 */
int BMP_Write(const char * outfile, BMPImage* img)
{
	// write header to the file
	// write image data to the file 
	return 1;
}

#endif



/* The input argument is the BMPImage pointer. The function frees memory of
 * the BMPImage.
 */
#ifndef BMP_FREE_FUNC
void BMP_Free(BMPImage* image)
{
	// free the data
}

#endif
