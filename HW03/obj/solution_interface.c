void mean_shift_s(double * * datapoints,
   int dim,
   int k,
   int weight_factor,
   int neighbour_distance,
   int iterations);

double * * allocate_memory_s(int no_points, int dim);

void deallocate_memory_s(double * * data, int no_points);

double * * get_neighbours_s(
   const double * datapoint,
   const double * * datapoints,
   int no_points,
   int dim,
   double neighbour_distance,
   int* no_neighbours);

double * find_mean_s(const double * datapoint,
   const double * * neighbours,
   int no_neighbours,
   int dim,
   int weight_factor);


#ifdef TEST_MEANSHIFT
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
	mean_shift_s(
	   datapoints,
	   dim,
	   k,
	   weight_factor,
	   neighbour_distance,
	   iterations);
}

#endif

#ifdef TEST_ALLOC
// allocate_memory function is used to allocate the memory for 2D arrays.
// Following arguments are used for this
// 1. no_points - number of rows in 2D array
// 2. dim - number of columns in 2D array
double * * allocate_memory(int no_points, int dim)
{
	return allocate_memory_s(no_points, dim);
}

#endif

#ifdef TEST_FREE
// deallocate_memory function is used to release memory for 2D arrays
// It takes 2 arguments:
// 1. double **data - this is pointer to the 2D array
// 2. no_points - number of points. Please be careful, it is number of rows and not number of cols
void deallocate_memory(double * * data, int no_points)
{
	deallocate_memory_s(data, no_points);
}

#endif

#ifdef TEST_NEIGHBOURS
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
	return get_neighbours_s(
		datapoint,
		datapoints,
		no_points,
		dim,
		neighbour_distance,
		no_neighbours);
}

#endif

#ifdef TEST_MEAN
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
	return find_mean_s(
			datapoint,
			neighbours,
			no_neighbours,
			dim,
			weight_factor);
}

#endif
