#include "sort.h"


/**
 * SwapIntegers - Swap two integers in an array.
 * @x: The first integer to SwapIntegers.
 * @y: The second integer to SwapIntegers.
 */
void SwapIntegers(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}


/**
 * selection_sort - Sort integer array in ascending order using selection sort
 *
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each SwapIntegers.
 *
 * Time Complexity: O(n^2)
*/
void selection_sort(int *array, size_t size)
{
	int *smaller = NULL;
	uint16_t i = 0;
	uint16_t j = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		smaller = array + i;
		for (j = i + 1; j < size; j++)
			smaller = (array[j] < *smaller) ? (array + j) : smaller;

		if ((array + i) != smaller)
		{
			SwapIntegers(array + i, smaller);

			print_array(array, size);
		}
	}
}

