/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPotentialCriminels.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 21:24:20 by mtan              #+#    #+#             */
/*   Updated: 2018/04/26 21:24:21 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <limits.h>

void	countSort(struct s_criminal **criminals, int n, int ex)
{
	struct s_criminal	*output[n];
	int					count[10] = {0};
	int 				i;

	i = 0;
	while (i < n)
		count[(criminals[i++]->description / ex) % 10]++;

	i = 0;
	while (++i < 10)
		count[i] += count[i - 1];

	i = n - 1;
	while (i >= 0)
	{
		output[count[(criminals[i]->description / ex) % 10 ] - 1] = criminals[i];
		count[(criminals[i--]->description / ex) % 10]--;
	}

	i = -1;
	while (++i < n)
		criminals[i] = output[i];
}

void	sortCriminals(struct s_criminal **criminals)
{
	int len = 0;

	while (criminals[len])
		len++;
	for (int i = 1; i < 10000000; i *= 10)
		countSort(criminals, len, i);
}

int		getDescription(struct s_info *info)
{
	return (
		info->gender * 1000000 +
		info->height * 100000 +
		info->hairColor * 10000 +
		info->eyeColor * 1000 +
		info->glasses * 100 +
		info->tattoo * 10 +
		info->piercing
	);
}

int	binarySearch(struct s_criminal **criminals, int start, int end, int value)
{
	if (end >= start)
	{
		int mid = start + (end - start) / 2;
		if (criminals[mid]->description == value)
			return (mid);
		if (criminals[mid]->description > value)
			return (binarySearch(criminals, start, mid - 1, value));
		else
			return (binarySearch(criminals, mid + 1, end, value));

	}
	return (-1);
}

struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info)
{
	int description = getDescription(info);
	int mid, left, right;
	int len = 0;

	while (criminals[len])
		len++;
	mid = binarySearch(criminals, 0, len - 1, description);
	left = mid;
	while (left > 0 && criminals[left - 1]->description == description)
		left--;
	right = mid;
	while (criminals[right + 1] && criminals[right + 1]->description == description)
		right++;
	criminals[right + 1] = 0;
	return (&criminals[left]);
}
