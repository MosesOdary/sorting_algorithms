#include "sort.h"

/**
 * get_max - function gets maximmum int size in array
 * @array: integer array
 * @size: array size
 * Return: maxim int in array
 */
int get_max(int *array, int size)
{
	int maxim, i;

	for (maxim = array[0], i = 1; i < size; i++)
	{
		if (array[i] > maxim)
			maxim = array[i];
	}

	return (maxim);
}

/**
 * counting_sort - array of integers sortedVal in ascending order
 * @array: integer array
 * @size: array size
 * Description: array is printed after being counted up
 */
void counting_sort(int *array, size_t size)
{
	int *counter, *sortedVal, maxim, i;

	if (array == NULL || size < 2)
		return;

	sortedVal = malloc(sizeof(int) * size);
	if (sortedVal == NULL)
		return;
	maxim = get_max(array, size);
	counter = malloc(sizeof(int) * (maxim + 1));
	if (counter == NULL)
	{
		free(sortedVal);
		return;
	}

	for (i = 0; i < (maxim + 1); i++)
		counter[i] = 0;
	for (i = 0; i < (int)size; i++)
		counter[array[i]] += 1;
	for (i = 0; i < (maxim + 1); i++)
		counter[i] += counter[i - 1];
	print_array(counter, maxim + 1);

	for (i = 0; i < (int)size; i++)
	{
		sortedVal[counter[array[i]] - 1] = array[i];
		counter[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sortedVal[i];

	free(sortedVal);
	free(counter);
}
