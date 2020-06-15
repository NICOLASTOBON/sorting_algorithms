#include "sort.h"
/**
 * swap - swap
 * @array: list
 * @low: low
 * @high: high
 * @size: size
 * Return: nothing
 */
void swap(int *array, int *low, int *high, size_t size)
{
	int tmp;

	tmp = *low;
	*low = *high;
	*high = tmp;

	print_array(array, size);
}
/**
 * partition - function partition and return index
 * @array: list
 * @low: low
 * @high: high
 * @size: size
 * Return: index
 */
int partition(int *array, int low, int high, size_t size)
{
	int j;
	int pivot = array[high];
	int i = low;

	for (j = low; j < high ; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
				swap(array, &array[i], &array[j], size);
			i++;
		}
	}
	if (i != j)
		swap(array, &array[i], &array[high], size);
	return (i);
}
/**
 * quick_sort_algo - function quick_sort_algo
 * @array: list
 * @low: low
 * @high: high
 * @size: size
 * Return: index
 */
void quick_sort_algo(int *array, int low, int high, size_t size)
{
	int pt;

	if (low < high)
	{
		pt = partition(array, low, high, size);

		quick_sort_algo(array, low, pt - 1, size);
		quick_sort_algo(array, pt + 1, high, size);
	}
}
/**
 * quick_sort - quick_sort
 * @array: list
 * @size: size
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_algo(array, 0, size - 1, size);
}
