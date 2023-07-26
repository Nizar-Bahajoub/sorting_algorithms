#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_ints - swap
 * @a: first int
 * @b: seconf int
 *
 * Return: nothing
 */

void swap_ints(int *a, int *b)
{
        int tmp;

        tmp = *a;
        *a = *b;
        *b = tmp;
}

/**
 * lomuto_partition - lomuto
 * @array: the array to be sorted
 * @size: the size of the array
 * @left: left
 * @right: right
 *
 * Return: an int
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
        int *driver, up, down;

        driver = array + right;
        for (up = down = left; down < right; down++)
        {
                if (array[down] < *driver)
                {
                        if (up < down)
                        {
                                swap_ints(array + down, array + up);
                                print_array(array, size);
                        }
                        up++;
                }
        }

        if (array[up] > *driver)
        {
                swap_ints(array + up, driver);
                print_array(array, size);
        }

        return (up);
}
/**
 * lomuto_sort - Sorts an integer array using Lomuto partition scheme
 *
 * This function implements the Lomuto partition scheme to choose a pivot
 * element,
 * then applies recursive quicksort to sort the array in ascending order.
 *
 * @array:   Pointer to the integer array to be sorted.
 * @size:    The number of elements in the array.
 * @left:    The index of the leftmost element of the current
 * partition.
 * @right:   The index of the rightmost element of the current
 * partition.
 *
 * Return: nothing
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
        int belong;

        if (right - left > 0)
        {
                belong = lomuto_partition(array, size, left, right);
                lomuto_sort(array, size, left, belong - 1);
                lomuto_sort(array, size, belong + 1, right);
        }
}
/**
 * quick_sort - Sorts an integer array using the quicksort algorithm.
 *
 * This function applies the quicksort algorithm to sort the array
 * in ascending order.
 * If the array is empty or has only one element, it is considered
 * already sorted.
 *
 * @array:   Pointer to the integer array to be sorted.
 * @size:    The number of elements in the array.
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
        if (array == NULL || size < 2)
                return;

        lomuto_sort(array, size, 0, size - 1);
}