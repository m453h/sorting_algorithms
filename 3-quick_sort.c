#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * lomuto_partition_sorter - Sorts an array using Lomuto partition strategy
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @left_part: The start index of the array partition to order
 * @right_part: The last index of the array partition to order
 *
 * Return: (int) - Partition index after sorting operation
 */
int lomuto_partition_sorter(int *array, size_t size, int left_part,
	int right_part)
{
	int pivot = array[right_part], high = left_part, tmp, i;

	for (i = left_part; i < right_part; i++)
	{
		if (array[i] < pivot)
		{
			if (high != i)
			{
				tmp = array[i];
				array[i] = array[high];
				array[high] = tmp;
				print_array(array, size);
			}
			high++;
		}
	}

	if (array[high] > pivot)
	{
		tmp = array[high];
		array[high] = array[right_part];
		array[right_part] = tmp;
		print_array(array, size);
	}

	return (high);
}

/**
 * quick_sort_helper - Helper to call lomuto partition sorter function
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @left_part: The start index of the array partition to order
 * @right_part: The last index of the array partition to order
 */
void quick_sort_helper(int *array, size_t size, int left_part, int right_part)
{
	int pivot;

	if (right_part < left_part)
		return;

	pivot = lomuto_partition_sorter(array, size, left_part, right_part);

	quick_sort_helper(array, size, pivot + 1, right_part);
	quick_sort_helper(array, size, left_part, pivot - 1);
}

/**
 * quick_sort - Sorts an array using quick sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, size, 0, (int)size - 1);
}
