#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_ints - swap function
 * @a: first int
 * @b: second int
 *
 * Return: void
*/

void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


/**
 * bubble_sort - bubble sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: Void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	int bubbly = 0;

	if (array == NULL || size < 2)
		return;

	while (bubbly == 0)
	{
		bubbly = 1;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, (array + i + 1));
				print_array(array, size);
				bubbly = 0;
			}
		}
		len--;
	}
}
