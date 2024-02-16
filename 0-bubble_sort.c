#include "sort.h"

/**
 *swap - swap values
 *@value_1: pointer to value_1
 *@value_2: pointer to value_2
 */
void swap(int *value_1, int *value_2)
{
	int temp;

	temp = *value_1;
	*value_1 = *value_2;
	*value_2 = temp;
}


/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: length of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swap_;

	if (array == NULL || size == 0 || size == 1)
		return;

	for (i = 0; i < size; i++)
	{
		swap_ = 0; /*flag to know when a swap occurs*/
		/* traverse the array and swap adjacent elements*/
		for (j = 0; j < (size - 1 - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&(array[j]), &(array[j + 1]));
				print_array(array, size);
				swap_ = 1;
			}
		}
		if (!swap_) /*stop the outer loop if no swaps were made*/
			break; /*no swap means the list is sorted*/
	}
}
