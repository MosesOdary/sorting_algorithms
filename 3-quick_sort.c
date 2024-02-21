#include "sort.h"


/**
 * quicksort0 - Implementation of quicksort
 * 
 * @arr: array to sort
 * @a: an integer
 * @b: an integer
*/
void quicksort0(int arr[], int a, int b)
{
	int key = 0;
	int size = b + 1;
	uint16_t i = 0;
	uint16_t j = 0;

	if (a >= b)
		return;

	key = arr[a];
	i = a + 1;
	j = b;
	
	while (i < j)
	{
		while (i < j && arr[j] >= key)
		{
			--j;
		}
	
		while (i < j && arr[i] <= key)
		{
			++i;
		}
	
		if (i < j)
		{
			Swap(arr, i, j);
			print_array(arr, size);
		}
	}
	if (arr[a] > arr[i])
	{
		Swap(arr, a, i);
	
		quicksort0(arr, a, i - 1);
		quicksort0(arr, i + 1, b);

		print_array(arr, size);
	}
	else
	{
		quicksort0(arr, a + 1, b);
	}
}

/**
 * quicksort - quicksort algorithm
 *
 * @array: Array to sort
 * @size: Array size
*/
void quick_sort(int *array, size_t size)
{
	quicksort0(array, 0, size - 1);	
}
