/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 10:00:48 by mtan              #+#    #+#             */
/*   Updated: 2018/04/30 17:23:09 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdbool.h>

char *getSum(char *a, char *b)
{
	int		sum;
	bool	carry = 0;

	for (int i = 5; i >= 0; i--)
	{
		a[i] -= '0';
		b[i] -= '0';
		sum = (a[i] ^ b[i]) ^ carry;
		carry = (a[i] & b[i]) | (a[i] & carry) | (b[i] & carry);
		a[i] = sum + '0';
	}
	return (a);
}

int toInt(char *bits)
{
	int n = 0;
	for (int i = 5; i >= 0; i--)
		n += (bits[i] - '0') * (1 << (5 - i));
	return (n);
}
