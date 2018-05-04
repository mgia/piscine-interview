/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 15:08:37 by mtan              #+#    #+#             */
/*   Updated: 2018/04/26 15:08:38 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	swap(struct s_player **first, struct s_player **second)
{
	struct s_player *tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

int		partition(struct s_player **A, int lo, int hi)
{
	int pivot = A[hi]->score;
	int i = lo - 1;

	for (int j = lo; j < hi; j++)
		if (A[j]->score < pivot)
			swap(&A[++i], &A[j]);
	swap(&A[i + 1], &A[hi]);
	return (i + 1);
}

void	recurse(struct s_player **A, int lo, int hi)
{
	if (lo < hi)
	{
		int p = partition(A, lo, hi);
		recurse(A, lo, p - 1);
		recurse(A, p + 1, hi);
	}
}

void	quickSort(struct s_player **players)
{
	int len = 0;

	while (players[len])
		len++;
	recurse(players, 0, len - 1);
}
