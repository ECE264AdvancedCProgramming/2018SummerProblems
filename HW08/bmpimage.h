#ifndef _BMPIMAGE_H
#define _BMPIMAGE_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAGIC_VALUE 0X4D42
#define BITS_PER_PIXEL 24
#define NUM_PLANE 1
#define COMPRESSION 0
#define BITS_PER_BYTE 8

#define BMP_HEADER_SIZE 54
#define DIB_HEADER_SIZE 40

#define TRUE 1
#define FALSE 0

// Tell compiler not to add space between the attributes
#pragma pack(1)
// A BMP file has a header (54 bytes) and data

typedef struct
{
   uint16_t type;		// Magic identifier 0x4d42
   uint32_t size;		// File size in bytes
   uint16_t reserved1;		// Not used
   uint16_t reserved2;		// Not used
   uint32_t offset;		// Offset to image data in bytes from beginning of file (54 bytes)
   uint32_t header_size;	// Header size in bytes
   uint32_t width;		// Width of the image
   uint32_t height;		// Height of the image
   uint16_t planes;		// Number of color planes
   uint16_t bits;		// Bits per pixel
   uint32_t compression;	// Compression type
   uint32_t image_size;		// Image size in bytes
   uint32_t x_resolution;	// Pixels per meter
   uint32_t y_resolution;	// Pixels per meter
   uint32_t n_colors;		// Number of colors
   uint32_t important_colors;	// Important colors
} BMPHeader;

typedef struct
{
   BMPHeader header;
   unsigned char* data;
} BMPImage;

BMPImage* BMP_Open(const char *filename);

// Check the validity of the header with the file from which the header is read
int Is_BMPHeader_Valid(BMPHeader *bmp_hdr);

// Write BMPImage to a given file
int BMP_Write(const char * outfile, BMPImage *image);

// Free memory in a given image
void BMP_Free(BMPImage *image);


#endif
