/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 10:09:04 by mtan              #+#    #+#             */
/*   Updated: 2018/04/30 10:09:12 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

char *rightShift(char *bin, int k)
{
	char *res = calloc(7, sizeof(char));
	for (int i = 5; i >= 0; i--)
		res[i] = (i - k > 0 ? bin[i - k] : bin[0]);
	return (res);
}

char *leftShift(char *bin, int k)
{
	char *res = calloc(7, sizeof(char));
	for (int i = 0; i < 6; i++)
		res[i] = (i + k < 6 ? bin[i + k] : '0');
	return (res);
}

int toInt(char *bits)
{
	int n = 0;
	int sign;

	sign = bits[0] - '0';
	for (int i = 1; i < 6; i++)
		n += ((bits[i] - '0') ^ sign) * (1 << (5 - i));
	n += sign;
	return (sign ? -n : n);
}
