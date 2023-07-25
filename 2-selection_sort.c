#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * my_swap - swap function
 * @a: the first int
 * @b: the second int
 *
 * Return: void
 */

void my_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - array selection sort
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, k, min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			my_swap(array + i, (array + min));
			for (k = 0; k < size - 1; k++)
				printf("%d, ", array[k]);
			printf("%d\n", array[size - 1]);
		}
	}
}
