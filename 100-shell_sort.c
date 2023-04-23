#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * get_interval - Calculate starting interval for sorting iterations
 *
 * @size: Size of the array to use in determining start interval
 * Return: (int) - The calculated interval
 */
size_t get_interval(size_t size)
{
	size_t interval = 1;

	while (interval < size / 3)
	{
		interval = interval * 3 + 1;
	}

	return (interval);
}

/**
 * shell_sort - Sorts an array using shell sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
	size_t interval, i, j;
	int temp;


	interval = get_interval(size);

	while (interval > 0)
	{
		i = interval;

		while (i < size)
		{
			temp = array[i];

			j = i;

			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];

				j = j - interval;
			}

			array[j] = temp;

			i++;
		}


		interval = (interval - 1) / 3;

		print_array(array, size);
	}
}
