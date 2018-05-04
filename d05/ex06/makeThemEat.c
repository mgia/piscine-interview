/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeThemEat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:20:58 by mtan              #+#    #+#             */
/*   Updated: 2018/05/02 16:20:58 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

int	recurse(struct s_people **people, int i, int nbTable, int totalTime, int *arr)
{
	if (!people[i])
		return (1);
	for (int j = 0; j < nbTable; j++)
	{
		if (arr[j] + people[i]->time <= totalTime)
		{
			arr[j] += people[i]->time;
			if (recurse(people, i + 1, nbTable, totalTime, arr))
				return (1);
			arr[j] -= people[i]->time;
		}
	}
	return (0);
}

int	isPossible(struct s_people **people, int nbTable, int totalTime)
{
	int	*arr = calloc(nbTable, sizeof(int));
	int	res = recurse(people, 0, nbTable, totalTime, arr);
	free(arr);
	return (res);
}
