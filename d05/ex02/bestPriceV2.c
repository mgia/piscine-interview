/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPriceV2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 11:00:17 by mtan              #+#    #+#             */
/*   Updated: 2018/05/02 11:00:18 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

double	getBest(int pizzaSize, double *cache, double *prices)
{
	if (cache[pizzaSize])
		return (cache[pizzaSize]);
	cache[pizzaSize] = prices[pizzaSize];
	for (int i = 1; i < pizzaSize; i++)
	{
		double tmp = getBest(i, cache, prices) + getBest(pizzaSize - i, cache, prices);
		if (tmp > cache[pizzaSize])
			cache[pizzaSize] = tmp;
	}
	return (cache[pizzaSize]);
}

double	optimizedBestPrice(int pizzaSize, double *prices)
{
	double *cache = calloc(pizzaSize, sizeof(double));
	double res = getBest(pizzaSize, cache, prices);
	free(cache);
	return (res);
}
