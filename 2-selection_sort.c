#include "sort.h"

/**
	* selection_sort - selection sort integer array
	* @array: the array to sort
	* @size: size of the array to sort
	*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, idx;

	for (i = 0; i < size - 1; i++)
	{
		idx = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[idx])
				idx = j;

		if (idx != i)
		{
			swap(&array[idx], &array[i]);
			print_array(array, size);
		}
	}
}
