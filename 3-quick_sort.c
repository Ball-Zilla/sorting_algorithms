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
 * lomuto_partition - divides and conquers
 * @array: The array of integers
 * @size: The size of the array
 * @lb: The lower bound
 * @ub: The upper bound
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int lb, int ub)
{
	int *piv, top, bottom;

	piv = array + ub;
	for (top = bottom = lb; bottom < ub; bottom++)
	{
		if (array[bottom] < *piv)
		{
			if (top < bottom)
			{
				swap_int(array + bottom, array + top);
				print_array(array, size);
			}
			top++;
		}
	}

	if (array[top] > *piv)
	{
		swap_int(array + top, piv);
		print_array(array, size);
	}

	return (top);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @lb: The lb
 * @ub: The ub
 *
 * Return: Nothing
 */
void lomuto_sort(int *array, size_t size, int lb, int ub)
{
	int piv;

	if (ub - lb > 0)
	{
		piv = lomuto_partition(array, size, lb, ub);
		lomuto_sort(array, size, lb, piv - 1);
		lomuto_sort(array, size, piv + 1, ub);
	}
}

/**
 * quick_sort - sorts an array using lomuto scheme
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
