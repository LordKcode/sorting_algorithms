#include "sort.h"

/**
 * shell_sort - sorts an array in ascending order using the Shell sort
 * @array: array to ordering
 * @size: size of array.
 */
void shell_sort(int *array, size_t size)
{
	size_t intv = 0, i, j;
	int temp = 0;

	if (array == NULL || size < 2)
		return;

	while (intv <= (size / 3))
	{
		intv = intv * 3 + 1;
	}

	while (intv > 0)
	{
		for (i = intv; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= intv && array[j - intv] > temp;
			     j -= intv)
			{
				array[j] = array[j - intv];
			}
			array[j] = temp;
		}
		print_array(array, size);
		intv = (intv - 1) / 3;
	}
}
