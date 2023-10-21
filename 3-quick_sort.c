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
	* partition - raarranges array
	* @array: array to arrange
	* @low: lowest position
	* @high: highest positon
	* @size: size of the array
	*
	* Return: index of pivot element
	*/
int partition(int *array, int size, int low, int high)
{
	int *pivot, above, below;

	pivot = array + high;
	for (above = below = low; below < high; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
	* _quick_sort - quick sort integer array recursivly
	*	@array: array to sort
	*	@low: lowest position
	*	@high: highest position
	* @size: size of the array
	*/
void _quick_sort(int *array, int size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, size, low, high);
		_quick_sort(array, size, low, pivot - 1);
		_quick_sort(array, size, pivot + 1, high);
	}
}

/**
	* quick_sort - quick sort integer array
	*	@array: array to sort
	*	@size: size of the array to sort
	*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	_quick_sort(array, size, 0, size - 1);
}
