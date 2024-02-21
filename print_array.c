#include "sort.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
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

