# Image Processing (Histogram Equalization) (Exercise)

## This is an exercise
In this exercise you will be implementing an important image processing algorithm which is used in scanned document processing, OCR, image segmentation, etc

<strong>Please read the entire file and the comments in the files provided before you ask any question.</strong><br>
<strong>You should write your own Makefile to test the code.</strong>


# Learning Goals
You will learn to
* Opening/Writing image files
* Working with Images
* Understand the color scale in images

# Description
This exercise requires you to do the following :
1. Open the colored BMP image
2. Convert the colored image to grayscale
3. Run Histogram Equalization algorithm on grayscale image
4. Save the new image in BMP format

## Histogram Equalization

Histogram Equalization increases the global contrast of images. Through this process, the intensities can be better distributed on the histogram. This allows for areas of lower local contrast to gain a higher contrast. Histogram equalization accomplishes this by spreading out the most frequent intensity values.

The method is useful in images with backgrounds and foregrounds that are both bright or both dark. In particular, the method can lead to better views of bone structure in x-ray images, and to better detail in photographs that are over or under-exposed. A key advantage of the method is that it is a fairly straightforward technique and an invertible operator. So in theory, if the histogram equalization function is known, then the original histogram can be recovered. The calculation is not computationally intensive.

## How to compute histogram equalization?

To understand what histogram equlization is let's discuss about histogram first.

Histogram of an image is the frequency distribution of each image pixel intensity value. What do I mean by that? If the image pixels values are {0, 123, 45, 123, 56, 123, 45, 21} then it's histogram would be { 0:1, 1:0, .... , 21:1, ....,  45: 2, ..., 56:1, ...., 123:3, 124:0, 125:0, .....255:0}, in the notation x:y `x` is the index and `y` is the value. What the histogram is doing is essentially counting how many times the value repeats in the image (i.e the frequency of each pixel).

Once this is done we calculate the the cumulative frequencies, which would look like:\
{0:1, 1:1, ......, 21:2, ......, 45: 4, ..., 56:5, ...., 123:8, .... 125:8, .... 255:8}\
The value at each poistion is the sum of frequencies upto that index, i.e freq at 56 = freq(0) + freq(1) .... + freq(56)\
The final step is to update the pixel value based on the cumulative frequencies.
Firstly we find the min frequency in our cumulative frequency. In the example above it will be 1 since the value lowest cumulative frequency value is 1 (i.e for index '0')

For a given input pixel value 'inp_i' the output pixel value 'out_i' is given by\
out_i = [(cumulative frequency(int_i) - min) / (number of pixels - min)] * 255

For example\
Intensity value for 123 would be calcuated as below:\
cumulative frequency(123) = 8\
min = 1\
number of pixels = 8 (i.e the number of elements in the original array {0, 123, 45, 123, 56, 123, 45, 21})\

out_i (123) = [(8-1) / (8-1)] * 255 = 255 (so value of 123 got mapped to 255)\

# Functions you need to complete
In this exercise, you have to complete six functions - `BMP_Open`, `Is_BMPHeader_Valid`,`BMP_Write`, `BMP_Free` in `bmpimage.c`;`ImgToGray` in `bmpfunc.c`; and `main()` in `pa08.c`.
**Do not hardcode the name of the files in your code**

**BONUS, This homework contains a bonus section. For the bonus section, you will need to complete HistogramEqualization method**
`HistogramEqualization`

1. `BMP_Open` -  This function takes the name of the file as input, opens up a file. Checks whether the file has right `BMP` header by calling `Is_BMPHeader_Valid` function. If everything is alright, then stores the value of pixels in the `data` . Finally returns BMPImage\* .
2. `Is_BMPHeader_Valid` - Checks whether the input file has right `BMP` header. You can refer to `Intermediate C Programming` to look for the correct checks for the header.
3. `BMP_Write` -  this function writes the output as `BMP` file. You should first write `BMP` header into the file and then you should write the BMP Image data into it.
4. `BMP_Free` - Frees up all the memory allocated for the image.
5. `ImgToGray` - This function takes input as the `BMP` image and then converts the image to `grayscale` (24-bit image with red=blue=green) by setting the red, blue, and green components of each pixel to the value obtained from calling `RGB2Gray` function. The output image should have red=blue=green for all pixels. If this function fails, print `"Error converting to Gray image\n"` and return `EXIT_FAILURE`.
6. `HistogramEqualization` **(BONUS)** - Use the image ouput from ImgToGray as input and apply the histogram equalization algorithm described above and return an pointer to the image.
7. `main()` - In this exercise, your main function has the following the specifications.
  1. if the arguments != 3 then print "Wrong arguments\n" and return
  2. 1st input name of the input file image. If opening up of this file fails print `Error opening BMP file`, and return `EXIT_FAILURE`.
  3. 2nd input output image file name.
  4. if file write fails, free memory and return EXIT_FAILURE
  
  a. The main function needs to open the image with dile name from argv[1].\
  b. Convert this image to grayscale image using the ImgToGray function.\
  c. An `equalize` function is provided to you in `equalize.h` and is linked via equalize.o this funtion does the histogram equalization. If you are working on the bonus call `HistogramEqualization` instead.\
  d. Write the equalzied image into the file whose nameis given by argv[2]

### Function already given to you :
**DO NOT modify this function**

`RGB2Gray` : this function takes red, green and blue value of a pixel as input and returns the gray value i.e. a number between 0-255

---------------------
# Testing your code
Following are the files we provide:
1. `pa08.c` - main file for this assignment.
2. `pa08.h` - Header file of the main file .
4. `bmpimage.h` - Header file, which has definition for the functions and structures you need in this assignment. Do not modify this file.
5. `bmpimage.c` - These contains the functions related to working with BMP images.
6. `bmpfunc.h` - Header file, which has definition for the functions you need in this assignment. Do not modify this file.
7. `bmpfunc.c` - Define your functions in this file. You can use any helper function you need but do not put them in the header file. Do not modify the functions that we have given you.
8. `Test-Cases/Expected/` - This directory contains the expected output as generated by the commands shown
	1. `expected1.bmp` - ./bin/pa08 Test-Cases/Test/img1.bmp Test-Cases/Expected/expected1.bmp
	2. `expected2.bmp` - ./bin/pa08 Test-Cases/Test/img2.bmp Test-Cases/Expected/expected2.bmp
	3. `expected3.bmp` - ./bin/pa08 Test-Cases/Test/img3.bmp Test-Cases/Expected/expected3.bmp

# Checking for memory errors
You should also run ./pa08 with arguments under valgrind. To do that, you have to use, for example, the following command:
```
valgrind --tool=memcheck --verbose --leak-check=full --log-file=valgrind.log ./pa08 Test-Cases/Test/img1.bmp Test-Cases/Expected/expected1.bmp
```

Note that you should use other input arguments to extensively test your function. If you follow the instructions and keep the malloc and free functions in the right place, you should not have memory problems in this assignment.


# Submitting Your code
** This is a programming assignment, so you would have to submit the code on Blackboard.**

The command to create zip file is as follows:
```

zip HW08.zip pa08.c bmpfunc.c bmpimage.c

```
<strong>You will not get any credits if the submitted file is not zipped</strong>

The **only** way to submit homework is through Blackboard.

The instructor will **never** accept any requestion for exception "*my
submission is only one minute late*".  It is your responsibility to
meet the deadline.  You are strongly encouraged to submit at least ten
minutes before the deadline because submission may take time.

If there is a campus-wide problem (such as network outage or the
Blackboard server is down), the deadline will be extended for the
entire class. If the problem is specific to yourself (for example,
your computer crashes), the deadline will not be extended for
you.

**DO NOT** send your code by email. Your code will not be graded
  if it is sent by email.

The teaching staff is strictly prohibited to look at files on your
computer (or your Purdue account) for grading. Thus, **NEVER** say "I
finished before the deadline but I forgot to submit".  **NEVER** say "I have
not made any change after the submission deadline." because the
teaching staff is not allowed to look at your files that have not been
submitted through Blackboard.


# Grading
If your program has any compilation error or warning (remember to use
`gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror`), you will
receive zero in this assignment.

In absolutely no circumstance can the teaching staff modify your
program for grading.  You cannot say, "If you change this, my program
works." If your program misses a semicolon and cannot compile, you
will receive zero.  Your score depends on what is submitted, nothing
else.

**The grading test cases will be made available along with the grades**
