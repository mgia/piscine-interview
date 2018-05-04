#include "header.h"
#include <stdio.h>
#include <string.h>

static void	merge(struct s_art **arts, int s, int m, int e)
{
	int i, j;
	int len1 = m - s + 1;
	int len2 = e - m;
	struct s_art *L[len1];
	struct s_art *R[len2];

	for (i = 0; i < len1; i++)
		L[i] = arts[s + i];
	for (j = 0; j < len2; j++)
		R[j] = arts[m + 1 + j];
	i = 0;
	j = 0;
	while (i < len1 && j < len2)
		if (strcmp(L[i]->name, R[j]->name) <= 0)
			arts[s++] = L[i++];
		else
			arts[s++] = R[j++];
	while (i < len1)
		arts[s++] = L[i++];
	while (j < len2)
		arts[s++] = R[j++];
}

static void	mergeSort(struct s_art **arts, int start, int end)
{
	if (start < end)
	{
		int middle = start + (end - start) / 2;
		mergeSort(arts, start, middle);
		mergeSort(arts, middle + 1, end);
		merge(arts, start, middle, end);
	}
}

void		sortArts(struct s_art **arts)
{
	int	len;

	len = 0;
	while (arts[len])
		len++;
	mergeSort(arts, 0, len - 1);
}
