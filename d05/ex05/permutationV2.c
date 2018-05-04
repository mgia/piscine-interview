/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 11:51:58 by mtan              #+#    #+#             */
/*   Updated: 2018/05/02 11:52:21 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "header.h"

void	swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void	permute(char *str, int l, struct s_dict *dict)
{
	if (!str[l] && dictSearch(dict, str) == -1)
	{
		dictInsert(dict, str, 1);
		printf("%s\n", str);
	}
	for (int i = l; str[i]; i++)
	{
		swap(&str[l], &str[i]);
		permute(str, l + 1, dict);
		swap(&str[l], &str[i]);
	}
}

void	printUniquePermutations(char *str)
{
	if (!str)
		return ;
	struct s_dict *dict = dictInit(strlen(str));
	permute(str, 0, dict);
}
