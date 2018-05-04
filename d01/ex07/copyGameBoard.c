/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyGameBoard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:00:05 by mtan              #+#    #+#             */
/*   Updated: 2018/04/25 21:52:40 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

int				listLen(struct s_node *list)
{
	int count = 0;
	while (list) {
		count++;
		list = list->next;
	}
	return (count);
}

struct s_node	*cloneGameBoard(struct s_node *node)
{
	struct s_node	*tmp;
	struct s_node	*last;
	struct s_node	*new;
	struct s_node	*res;
	int 			len = listLen(node);
	struct s_node	*dict[len];

	if (!node)
		return (NULL);
	last = NULL;
	tmp = node;
	while (tmp)
	{
		new = malloc(sizeof(struct s_node));
		new->value = tmp->value;
		new->random = NULL;
		if (!last)
			res = new;
		else
			last->next = new;
		dict[new->value] = new;
		last = new;
		tmp = tmp->next;
	}
	tmp = node;
	while (tmp)
	{
		if (tmp->random)
			dict[tmp->value]->random = dict[tmp->random->value];
		tmp = tmp->next;
	}
	return (res);
}
