/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 10:00:40 by mtan              #+#    #+#             */
/*   Updated: 2018/04/30 10:00:41 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

char *getAnd(char *a, char *b)
{
	int bit_a;
	int neg_a = (a[0] == '~');
	int bit_b;
	int neg_b = (b[0] == '~');
	char *res = calloc(5, sizeof(char));
	for (int i = 0; i < 4; i++)
	{
		bit_a = (a[i + neg_a] - '0') ^ neg_a;
		bit_b = (b[i + neg_b] - '0') ^ neg_b;
		res[i] = (bit_a & bit_b) + '0';
	}
	return (res);
}

char *getOr(char *a, char *b)
{
	int bit_a;
	int neg_a = (a[0] == '~');
	int bit_b;
	int neg_b = (b[0] == '~');
	char *res = calloc(5, sizeof(char));
	for (int i = 0; i < 4; i++)
	{
		bit_a = (a[i + neg_a] - '0') ^ neg_a;
		bit_b = (b[i + neg_b] - '0') ^ neg_b;
		res[i] = (bit_a | bit_b) + '0';
	}
	return (res);
}

int toInt(char *bits)
{
	int n = 0;
	for (int i = 0; i < 4; i++)
		n += (bits[i] - '0') * (1 << (3 - i));
	return (n);
}
