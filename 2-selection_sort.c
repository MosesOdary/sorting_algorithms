#include "sort.h"

/**
* selection_sort - function to perform selectionsorting
*
* @array: memory for data items
* @size: data items' size
*
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

/**
* Swap - function to enable swapping of data items
*
* @array: memory block holding data iems to be sorted
* @first: first data item to be compared with second for sorting
* @second: second data for comparison and swapping
*
* Return: nothing to return
*/
void Swap(int array[], size_t first, size_t second)
{
	int temp = array[first];

	array[first] = array[second];
	array[second] = temp;
}

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
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
