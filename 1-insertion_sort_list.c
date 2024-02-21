#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	for (size_t i = 1; i < length; i++)
    {
        size_t moveItem = i;
        int insert = array[i];

        while (moveItem > 0 && array[moveItem - 1] > insert)
        {
            array[moveItem] = array[moveItem - 1];
            --moveItem;
        }
        array[moveItem] = insert;
    }
}
