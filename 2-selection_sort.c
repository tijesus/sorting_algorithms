#include "sort.h"

/**
 * selection_sort - sort array of integers in ascending order
 * @array: array of integers
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t j, i, smallest_index;
	int tmp;

	if (array == NULL || size == 1)
		return;

	for (j = 0; j < size; j++)
	{
		smallest_index = j;
		for (i = j + 1; i < size; i++)
		{	/*update the smallest index*/
			if (array[i] < array[smallest_index])
				smallest_index = i;
		}
		if (smallest_index != j)
		{	/*swap*/
			tmp  = array[smallest_index];
			array[smallest_index] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
}
