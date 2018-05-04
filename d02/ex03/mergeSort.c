/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:05:06 by mtan              #+#    #+#             */
/*   Updated: 2018/04/26 16:05:07 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>

static void	merge(struct s_player **A, int s, int m, int e)
{
	int i, j;
	int len1 = m - s + 1;
	int len2 = e - m;
	struct s_player *L[len1];
	struct s_player *R[len2];

	for (i = 0; i < len1; i++)
		L[i] = A[s + i];
	for (j = 0; j < len2; j++)
		R[j] = A[m + 1 + j];
	i = 0;
	j = 0;
	while (i < len1 && j < len2)
		if (L[i]->score < R[j]->score)
			A[s++] = L[i++];
		else
			A[s++] = R[j++];
	while (i < len1)
		A[s++] = L[i++];
	while (j < len2)
		A[s++] = R[j++];
}

static void	mergeSort1(struct s_player **A, int start, int end)
{
	if (start < end)
	{
		int middle = start + (end - start) / 2;
		mergeSort1(A, start, middle);
		mergeSort1(A, middle + 1, end);
		merge(A, start, middle, end);
	}
}

struct s_player	**mergeSort(struct s_player **players)
{
	int	len;

	len = 0;
	while (players[len])
		len++;
	mergeSort1(players, 0, len - 1);
	return (players);
}
