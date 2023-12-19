#include "sort.h"

/**
 * swap_int - swaps integers
 * @a: address of int
 * @b: address of int
 *
 * Return: nothing
 */
void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - sorts an array of integers
 * @array: pointer to the array
 * @size: size of the array
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	if (!(array && size > 1))
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			swap_int(&array[i], &array[min_idx]);
			print_array(array, size);
		}
	}
}
