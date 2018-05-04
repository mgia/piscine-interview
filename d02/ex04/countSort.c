/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:19:26 by mtan              #+#    #+#             */
/*   Updated: 2018/04/26 16:19:26 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <limits.h>

int		getMax(unsigned char *utensils, int n)
{
	int	max = INT_MIN;
	int	i = -1;

	while (++i < n)
		if (max < utensils[i])
			max = utensils[i];
	return (max);
}

void	countSort(unsigned char *utensils, int n)
{
	int max = getMax(utensils, n);
	int	count[max];
	int i;

	memset(count, 0, sizeof(count));
	i = 0;
	while (i < n)
		count[utensils[i++]]++;
	i = 0;
	while (i <= max)
	{
		memset(utensils, i, count[i]);
		utensils += count[i++];
	}
}
