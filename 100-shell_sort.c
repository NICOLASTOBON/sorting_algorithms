#include "sort.h"
/**
 * gap - sequence of intervals
 * @size: size
 * Return: interval
 */
int gap(size_t size)
{
	size_t i;

	for (i = 1; i < size; i *= 3 + 1)
		;
	return ((i - 1) / 3);
}
/**
 * shell_sort - sequence of intervals
 * @size: size
 * @array: is the list
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	int gap_num, i, tmp, j;

	gap_num = gap(size);

	while (gap_num > 0)
	{
		for (i = gap_num; i < (int)size; i++)
		{
			tmp = array[i];

			for (j = i; j >= gap_num && array[j - gap_num] > tmp; j -= gap_num)
				array[j] = array[j - gap_num];

			array[j] = tmp;
		}
		gap_num = (gap_num - 1) / 3;
		print_array(array, size);
	}
}
