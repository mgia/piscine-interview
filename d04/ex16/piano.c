/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piano.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 10:49:13 by mtan              #+#    #+#             */
/*   Updated: 2018/05/01 11:00:17 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include <stdio.h>

int **pianoDecompress(struct s_bit *bit, int l)
{
	int	**res = calloc(bit->n + 1, sizeof(int*));
	int	n;
	for (int i = 0; i < bit->n; i++)
	{
		res[i] = calloc(l, sizeof(int));
		n = bit->arr[i];
		for (int j = 0; j < l; j++)
		{
			res[i][j] = n & 1;
			n >>= 1;
		}
	}
	return res;
}
