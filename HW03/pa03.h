#ifndef PE03_H
#define PE03_H

#include <stdlib.h>
#define M_PI 3.14159265358979323846

/*Caution:
 * Do not modify any functions in this file.
 * */

// euclid_distance - this function calculates the Euclidean distance between the mean and the data point. 
// It has three arguments as inputs const double * datapoint, const double * mean & int dim
// 1. const double * datapoint - this is a pointer (an array of dim elements) to datapoint from which distance
// needs to be calculated. It is const because we don't want the function to change the value of data.
// 2. double * mean - As the name suggests this is pointer to the mean, which has dim elements.
// 3. int dim - this is the dimension of the datapoint.

// You need to add -lm after -o pe02 in Makefile to link the math library
double euclid_distance(const double * datapoint, const double * mean, int dim);


// This method calculates the weight that needs to be used to fin the mean.
// Go through the readme file on how to implement this funcation.
double get_weight(double distance, int weight_factor);


#endif
