#include "sort.h"

/**
	* swap - swap two integers
	* @lhs: first integer
	* @rhs: second integer
	*/
void swap(int *lhs, int *rhs)
{
	int tmp = *lhs;
	*lhs = *rhs;
	*rhs = tmp;
}

/**
	* selection_sort - selection sort integer array
	* @array: the array to sort
	* @size: size of the array to sort
	*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, idx;

	if (!array || size < 2)
		return;

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
