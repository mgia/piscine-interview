/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:55:47 by mtan              #+#    #+#             */
/*   Updated: 2018/04/25 19:55:49 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void printReverse(struct s_node *lst)
{
	static int i = 0;

	if (!lst)
		return;

	i++;
	printReverse(lst->next);
	printf("%s", lst->word);
	i--;
	printf("%c", i ? ' ' : '\n');
}
