#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "pa03.h"

// Function declaration
void mean_shift(double * * datapoints,
   int dim,
   int k,
   int weight_factor,
   int neighbour_distance,
   int iterations);

// Function declaration
double * * allocate_memory(int no_points, int dim);

// Function declaration
void deallocate_memory(double * * data, int no_points);


bool read_data(FILE * fpin, double * * data, int no_points, int dim)
{
   int niter, diter;
   for (niter = 0; niter < no_points; niter++)
   {
      for (diter = 0; diter < dim; diter++)
      {
         if (fscanf(fpin, "%lf", &data[niter][diter]) == 0)
         {
            return false;
         }
      }
   }

   return true;
}

void write_means(FILE * fpout, double * * means, int no_points, int dim)
{
   int kiter, diter;
   for (kiter = 0; kiter < no_points; kiter++)
   {
      for (diter = 0; diter < dim; diter++)
      {
         // Write to the file
         fprintf(fpout, "%lf ", means[kiter][diter]);
      }

      fprintf(fpout, "\n");
   }
}

void cleanup(FILE * fpin, FILE * fpout)
{
   fclose(fpin);
   fclose(fpout);
}

int main(int argc, char ** argv)
{
   // Inputs 2D array 
   // Each row is a data point
   // And we have 'k' such points
   // Each row is 'dim' wide
   // because we do not know prior to execution how many we would need
   // ideally mean would be a linked list

   int k, dim, weight_factor, neighbour_distance, iterations;

   // argv[1]: name of input file
   // argv[2]: name of output file

   if (argc < 3)
   {
      fprintf(stderr, "argc is %d, not 3\n", argc);
      return EXIT_FAILURE;
   }

   FILE * fpin = fopen(argv[1], "r");
   if (fpin == NULL)
   {
      fprintf(stderr, "fopen %s fail\n", argv[1]);
      return EXIT_FAILURE;
   }

   FILE * fpout = fopen(argv[2], "w");
   if (fpout == NULL)
   {
      fclose(fpin);
      // was open successfully and needs to be closed
      fprintf(stderr, "fopen %s fail\n", argv[3]);
      return EXIT_FAILURE;
   }

   if (argc == 5)
   {
      weight_factor = (int)strtol(argv[2], NULL, 10);
      neighbour_distance = (int)strtol(argv[3], NULL, 10);
      iterations = (int)strtol(argv[4], NULL, 10);
   }
   else
   {
      weight_factor = 12;
      neighbour_distance = 100;
      iterations = 100;
   }

   fscanf(fpin, "%d", &k);
   fscanf(fpin, "%d", &dim);

   // Allocate memory for the data points
   double * * datapoints = allocate_memory(k, dim);
   if (datapoints == NULL)
   {
      cleanup(fpin, fpout);
      return EXIT_FAILURE;
   }

   // Read the data from the file
   if (read_data(fpin, datapoints, k, dim) == false)
   {
      cleanup(fpin, fpout);
      return EXIT_FAILURE;
   }

   // For this assignment this will call the provided mean_shift implementation
   mean_shift(datapoints, dim, k, weight_factor, neighbour_distance, iterations);

   // Print all the means into a file
   write_means(fpout, datapoints, k, dim);
   
   // Free memory allocated to datapoints
   deallocate_memory(datapoints, k);

   cleanup(fpin, fpout);
   return EXIT_SUCCESS;
}


#ifndef TEST_MEANSHIFT

// The mean_shift method to cluster data
// datapoints:  two-dimensional array of the data, k rows, dim columns
// k: the number of data points
// dim: dimension of the data
// weight_factor: a number that is used to calculate the weighted mean for each datapoint
// neighbour_distance: the distance from the datapoint to look for neighbours
// iterations: number of iterations to be run for
// Note that the means should be updated onto the datapoints array
void mean_shift(double * * datapoints,
   int dim,
   int k,
   int weight_factor,
   int neighbour_distance,
   int iterations)
{
   // Please complete this method

   // While all points are not done
   // 1. Find neighbours
   // 1. Calculate mean
   // 2. Update mean
}

#endif



#ifndef TEST_ALLOC

// allocate_memory function is used to allocate the memory for 2D arrays.
// Following arguments are used for this
// 1. no_points - number of rows in 2D array
// 2. dim - number of columns in 2D array
double * * allocate_memory(int no_points, int dim)
{
   double * * data = NULL;
   // TODO: allocate memory for the data and then return the data
   // It is this functions reponsibility to ensure that memory is allocated
   return data;
}

#endif


#ifndef TEST_FREE

// deallocate_memory function is used to release memory for 2D arrays
// It takes 2 arguments:
// 1. double **data - this is pointer to the 2D array
// 2. no_points - number of points. Please be careful, it is number of rows and not number of cols
void deallocate_memory(double * * data, int no_points)
{
   // TODO: complete this function to release the memory of the data
   // not completing this function will lead to memory not getting free
}

#endif

#ifndef TEST_NEIGHBOURS
// For a data point, find the closest neighbouring data points which are at a distance lesser than "neighbour_distance"
// 1. Calculate the distance between the data point and to all of the datapoints
// 2. If distance is less than or equal to the "neighbour_distance"
// 3. Return the set of neighbours as a array of pointers (i.e. 2D array)
// const double * datapoint - the point under consideration
// const double * *datapoints - All the points in the cluster (2D Array, cols = dim, rows = number of points)
// int no_points - the number of rows of the 2D array double ** datapoints
// int dim - the number of columns of the 2D array double ** datapoints
// double neighbour_distance - the threshold distance above which neighbours are not considered
// int* no_neighbours - returns the number of neighbours by updating the value pointed to by the pointer
// make sure to initalize this value to zero in the begining
double * * get_neighbours(
   const double * datapoint,
   const double * * datapoints,
   int no_points,
   int dim,
   double neighbour_distance,
   int* no_neighbours)
{
   double * * data = NULL;

   // TODO: return a 2D array of neighbouring points within 'neighbour_distance' from 'datapoint' 
   return data;
}

#endif


#ifndef TEST_MEAN
// find_mean - This method calculates the weighted mean for all the neighbouring data points.
// 1. * const double * datapoint- This is the point for which we are calculating the mean. It is an array of dim elements.
// 2. const double * * neighbours - This is a 2D array of points. Number of rows is no_neighbours. And has dim columns.
// 3. int no_neighbours - This value informs how many neighbours are being considered for the particular datapoint.
// 4. int dim - this is the dimension of the datapoint and neighbours
// 5. int weight_factor - this is the weight factor for the used to calculate the weight, passed to get_weight function
// use pa03.h to figure out how to call get_weight;
// If you want to you can use the get_weight funcation you wrote in HW02. If not an implementation is provided to you in the form
// of get_weight.o which will get linked if you use the provided makefile.
double * find_mean(const double * datapoint,
   const double * * neighbours,
   int no_neighbours,
   int dim,
   int weight_factor)

{
   return NULL;
}

#endif
