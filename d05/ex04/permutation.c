/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:20:48 by mtan              #+#    #+#             */
/*   Updated: 2018/05/02 16:20:49 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void	permute(char *str, int l)
{
	if (!str[l])
		printf("%s\n", str);
	for (int i = l; str[i]; i++)
	{
		swap(&str[l], &str[i]);
		permute(str, l + 1);
		swap(&str[l], &str[i]);
	}
}

void	printPermutations(char *str)
{
	if (!str)
		return ;
	permute(str, 0);
}
