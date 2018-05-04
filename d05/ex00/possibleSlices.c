/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibleSlices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:43:39 by mtan              #+#    #+#             */
/*   Updated: 2018/05/01 17:43:40 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "header.h"

void	recurse(struct s_array *arr, int n)
{
	if (!n)
	{
		arrayPrint(arr);
		free(arr);
	}
	for (int i = n; i > 0; i--)
	{
		struct s_array *clone = arrayClone(arr);
		arrayAppend(clone, i);
		recurse(clone, n - i);
	}
}

void	printPossibleSlices(int pizzaSize)
{
	struct s_array	*arr = arrayInit();
	recurse(arr, pizzaSize);
}
