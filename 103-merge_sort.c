#include "sort.h"

/**
 * merge_array - Sorting of integers.
 * @arr: A subarray of an array of integers to sort.
 * @buf: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_array(int *arr, int *buf, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(arr + front, mid - front);

	printf("[right]: ");
	print_array(arr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buf[k] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
	for (; i < mid; i++)
		buf[k++] = arr[i];
	for (; j < back; j++)
		buf[k++] = arr[j];
	for (i = front, k = 0; i < back; i++)
		arr[i] = buf[k++];

	printf("[Done]: ");
	print_array(arr + front, back - front);
}

/**
 * merge_sort_recur - merge sorting algorithm using recursion.
 * @arr: A subarray of an array of integers to sort.
 * @buf: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_recur(int *arr, int *buf, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recur(arr, buf, front, mid);
		merge_sort_recur(arr, buf, mid, back);
		merge_array(arr, buf, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buf;

	if (array == NULL || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	merge_sort_recur(array, buf, 0, size);

	free(buf);
}
