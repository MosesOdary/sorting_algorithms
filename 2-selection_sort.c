#include "sort.h"

/*
* selection_sort - function to perform selectionsorting
* @array: memory for data items
* @size: data items' size
* Return: nothing to return
*/
void selection_sort(int *array, size_t size)
{
	uint16_t i = 0;
	uint16_t j = 0;
	uint32_t smallest = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		smallest = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smallest])
			{
				smallest = j;
			}
		}
		Swap(array, i, smallest);
		print_array(array, size);
	} 
}

/*
* Swap - function to enable swapping of data items
* @array: memory block holding data iems to be sorted
* @first: first data item to be compared with second for sorting
* @second: second data for comparison and swapping
* Return: nothing to return
*/
void Swap(int array[], size_t first, size_t second)
{
	int temp = array[first];
	array[first] = array[second];
	array[second] = temp;
}
