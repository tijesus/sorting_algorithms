#include "sort.h"

/**
 * partition - partition the array arround a pivot
 * @array: integer array
 * @start: start of the array
 * @end: end of the array
 * @size: array size
 * Return: the pivot's index
 */
size_t partition(int *array, size_t start, size_t end, size_t size)
{
	size_t i, j;
	int temp;

	i = start;
	for (j = start; j < end + 1; j++)
	{
		if (array[j] <= array[end])
		{
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			if (i != j)
				print_array(array, size);
			i++;
		}
	}
	return (i - 1); /*the index of the pivot element*/
}

/**
 * __quick_sort - sort array using quick sort algorithm
 * @array: the array to be sorted
 * @start: what index to start the sorting
 * @end: what index to end the sorting
 * @size: array size
 */
void __quick_sort(int *array, int start, int end, size_t size)
{
	size_t partition_index;

	if (start < end)
	{
		partition_index = partition(array, start, end, size);
		__quick_sort(array, start, partition_index - 1, size);
		__quick_sort(array, partition_index + 1, end, size);
	}
}

/**
 * quick_sort - sort an integer array using quick sort
 *              algorithm
 * @array: integer array
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	size_t start;
	size_t end;

	start = 0;
	end = size - 1;
	__quick_sort(array, start, end,  size);
}
