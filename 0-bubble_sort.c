#include "sort.h"
/**
* bubble_sort - sort an int array with bubble_sort
* @array: array of integers of size
* @size: the size of the array
*/
void bubble_sort(int *array, size_t size)
{
	/* declarations */
	int temp;
	size_t i, j;

	/* check for array & size */
	if (!(array && size))
		return;

	/* sort */
	for (i = 0; i < size;)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
		i++;
	}
}
