#include "sort.h"


/**
 * SwapIntegers - Swap two integers in an array.
 * @a: The first integer to SwapIntegers.
 * @b: The second integer to SwapIntegers.
 */

void SwapIntegers(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}


/**
 * selection_sort - Sort an array of integers in ascending order using selection sort
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

int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    selection_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
