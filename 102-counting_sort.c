#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * get_largest - Determines the largest integer in array
 *
 * @array: The array to determine the largest integer
 * @size: Number of elements in @array
 *
 * Return: (int) - The largest integer in @array
 */
int get_largest(int *array, size_t size)
{
	int largest = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > largest)
			largest = array[i];
	}

	return (largest);
}

/**
 * counting_sort - Sorts an array using counting sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Return: (void) Nothing
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *sorted_array, largest, i, n_count_items, n_sorted_items;

	if (array == NULL || size < 2)
		return;

	largest = get_largest(array, size);
	n_count_items = largest + 1;
	count_array = malloc(sizeof(int) * n_count_items);
	n_sorted_items = (int)size;
	sorted_array = malloc(sizeof(int) * size);

	if (count_array == NULL || sorted_array == NULL)
	{
		free(count_array);
		free(count_array);
		return;
	}

	for (i = 0; i <= n_count_items; i++)
		count_array[i] = 0;

	for (i = 0; i < n_sorted_items; i++)
		count_array[array[i]]++;

	for (i = 1; i <= largest; i++)
		count_array[i] += count_array[i - 1];

	print_array(count_array, n_count_items);

	for (i = n_sorted_items - 1; i >= 0; i--)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	for (i = 0; i < n_sorted_items; i++)
		array[i] = sorted_array[i];

	free(sorted_array);
	free(count_array);
}
