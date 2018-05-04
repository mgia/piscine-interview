/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPrice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 18:33:02 by mtan              #+#    #+#             */
/*   Updated: 2018/05/01 18:33:03 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void recurse(int pizzaSize, double *best, double sum, double *prices)
{
	if (pizzaSize <= 0)
	{
		if (sum > *best)
			*best = sum;
		return ;
	}
	for (int i = 1; i <= pizzaSize; i++)
		recurse(pizzaSize - i, best, sum + prices[i], prices);
}

double bestPrice(int pizzaSize, double *prices)
{
	double best = 0;
	recurse(pizzaSize, &best, 0, prices);
	return (best);
}
