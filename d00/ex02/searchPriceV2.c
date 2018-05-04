/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:51:57 by mtan              #+#    #+#             */
/*   Updated: 2018/04/23 10:52:00 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

int		binarySearch(struct s_art **arts, int s, int e, char *name)
{
	if (s < e)
	{
		int m = s + (e - s) / 2;
		int res = strcmp(arts[m]->name, name);
		if (!res)
			return (arts[m]->price);
		else if (res > 0)
			return (binarySearch(arts, s, m, name));
		else
			return (binarySearch(arts, m + 1, e, name));
	}
	return (-1);
}

int 	searchPrice(struct s_art **arts, int n, char *name)
{
	return (binarySearch(arts, 0, n - 1, name));
}
