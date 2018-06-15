#ifndef PE02_H
#define PE02_H

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


// The mean_shift method to cluster data
// datapoints:  two-dimensional array of the data, k rows, dim columns
// k: the number of data pointers
// dim: dimension of the data
// weight_factor: a number that is used to calculate the weighted mean for each datapoint
// neighbour_distance: the distance from the datapoint to look for neighbours
// iterations: number of iterations to be run for
void mean_shift(double * * datapoints,
   int dim,
   int k,
   int weight_factor,
   int neighbour_distance,
   int iterations);


// allocate_memory function is used to allocate the memory for 2D arrays.
// Following arguments are used for this
// 1. no_points - number of rows in 2D array
// 2. dim - number of columns in 2D array
double * * allocate_memory(int no_points, int dim);


// deallocate_memory function is used to release memory for 2D arrays
// It takes 2 arguments:
// 1. double **data - this is pointer to the 2D array
// 2. no_points - number of points. Please be careful, it is number of rows and not number of cols
void deallocate_memory(double * * data, int no_points);


// This method calculates the weight that needs to be used to fin the mean.
// Go through the readme file on how to implement this funcation.
double get_weight(double distance, int weight_factor);


#endif
