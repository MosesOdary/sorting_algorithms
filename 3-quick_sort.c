#include "sort.h"


/**
 * SwapIntegers - Swap two integers in an array.
 *
 * @x: First integer
 * @y: Second integer
 */
void SwapIntegers(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}


/**
 * lomuto_partition - Order array subset of integers
 *
 * @array: The array of integers
 * @size: The size of the array
 * @left: The starting index of the subset to order
 * @right: The ending index of the subset to order
 *
 * Return: The final partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot = NULL;
	int above = 0;
	int below = 0;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				SwapIntegers(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		SwapIntegers(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm recursively
 *
 * @array: An array of integers to sort
 * @size: The size of the array
 * @left: The starting index of the array partition to order
 * @right: The ending index of the array partition to order
 *
 * Description: Uses Lomuto partition scheme
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order using quicksort
 *
 * @array: An array of integers
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
