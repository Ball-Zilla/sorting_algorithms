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
 * shell_sort - sorts an array of ints
 * @array: pointer to the array
 * @size: size of the array
 *
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t  gap, i, j;

	if (!(array && size > 1))
		return;

	for (gap = 1; gap < (size / 3); gap = gap * 3 + 1)
		;
	for (; gap >= 1; gap /= 3)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; &array[i] >= array; i -= gap)
			{
				if (array[i] > array[i + gap])
					swap_int(&array[i], &array[i + gap]);
				else
					break;
			}
		}
		print_array(array, size);
	}
}
