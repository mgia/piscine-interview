#include <stdio.h>

void aloneCans(int *arr, int n)
{
	int can1 = 0;
	int can2 = 0;
	int	mask = 0;

	for (int i = 0; i < n; i++)
		mask ^= arr[i];
	mask &= ~(mask - 1);
	for (int i = 0; i < n; i++)
	{
		if (arr[i] & mask)
			can1 ^= arr[i];
		else
			can2 ^= arr[i];
	}
	printf("%d\n%d\n", can1, can2);
}
