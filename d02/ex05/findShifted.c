/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findShifted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 19:32:02 by mtan              #+#    #+#             */
/*   Updated: 2018/04/26 19:32:03 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		search(int *rocks, int l, int r, int key)
{
	int		mid = l + (r - l) / 2;

	if (l > r)
		return (-1);
	else if (rocks[mid] == key)
		return (mid);
	else if (rocks[l] <= rocks[mid])
	{
		if (key >= rocks[l] && key < rocks[mid])
			return (search(rocks, l, mid, key));
		return (search(rocks, mid + 1, r, key));
	} else
	{
		if (key >= rocks[mid] && key <= rocks[r])
			return (search(rocks, mid + 1, r, key));
		return (search(rocks, l, mid, key));
	}
}

int		searchShifted(int *rocks, int length, int value)
{
	int		res;

	res = search(rocks, 0, length - 1, value);
	if (res < 0)
		return (res);
	while (res >= 0 && rocks[res] == value)
		res--;
	return (res + 1);
}
