#include "sort.h"
#include <stdbool.h>

/**
	* bubble_sort - bubble sort integer array
	* @array: the array to sort
	* @size: size of the array to sort
	*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}
