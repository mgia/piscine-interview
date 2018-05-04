/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPalindrome.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:44:08 by mtan              #+#    #+#             */
/*   Updated: 2018/05/02 16:44:09 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char	*isPalindrome(char *str)
{
	int i = 0;
	int j = strlen(str) - 1;

	while (i < j)
		if (str[i++] != str[j--])
			return (0);
	return (str);
}

char	*shorten(char *str, int skip)
{
	int		len = strlen(str), j = 0;
	char	*res = calloc(len, sizeof(char));
	for (int i = 0; i < len; i++)
	{
		if (i != skip)
			res[j++] = str[i];
	}
	return (res);
}

char	*findPalindrome(char *sequence, int nDelete)
{
	char	*tmp, *res;

	if (!sequence)
		return (NULL);
	if (!nDelete)
		return (isPalindrome(sequence));
	for (int i = 0; sequence[i]; i++)
	{
		tmp = shorten(sequence, i);
		if ((res = findPalindrome(tmp, nDelete - 1)))
			return (res);
		free(tmp);
	}
	return (NULL);
}
