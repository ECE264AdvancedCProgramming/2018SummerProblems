#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "pe02.h"


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


#ifndef TEST_EUCLID

// euclid_distance - this function calculates the Euclidean distance between the mean and the data point. 
// It has three arguments as inputs const double * datapoint, const double * mean & int dim
// 1. const double * datapoint - this is a pointer (an array of dim elements) to datapoint from which distance
// needs to be calculated. It is const because we don't want the function to change the value of data.
// 2. double * mean - As the name suggests this is pointer to the mean, which has dim elements.
// 3. int dim - this is the dimension of the datapoint.

// You need to add -lm after -o pe02 in Makefile to link the math library
double euclid_distance(const double * datapoint, const double * mean, int dim)
{
   // Must initialize to zero
   double sum = 0;
  
   //Please complete this method
   return sum;
}

#endif

#ifndef TEST_WEIGHT
// get_weight - This function is needed to find the weight for the weighted mean that we be performed to calculate the mean.
// 1. double distance - this is the distance of the point from the mean.
// 2. int weight_factor - this is the weight factor for the used to calculate the weight see the formula below
// See the readme file on how to implement this function
double get_weight(double distance, int weight_factor)
{
   //Please complete this method
   return 0.0;
}

#endif


