/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printYoungest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 21:43:19 by mtan              #+#    #+#             */
/*   Updated: 2018/04/26 21:43:20 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>
#include <stdio.h>

int		min(int *ages, int left, int right)
{
	if (left == right)
		return (ages[left]);

	int mid = (left + right) / 2;
	return (fmin(min(ages, left, mid), min(ages, mid + 1, right)));
}

void	printYoungest(int *ages, int length)
{
	printf("Youngest : %d\n", min(ages, 0, length - 1));
}
