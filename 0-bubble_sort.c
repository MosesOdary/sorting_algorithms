#include "sort.h"



void bubble_sort(int *array, size_t size)
{
	uint16_t i = 0;
	uint16_t j = 0;
	uint64_t temp = 0;

	for (; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				print_array(array, size);
			}
		}
	}
}

