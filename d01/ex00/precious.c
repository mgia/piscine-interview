/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 11:22:35 by mtan              #+#    #+#             */
/*   Updated: 2018/04/25 11:22:35 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

struct s_node	*createElem(char c)
{
	struct s_node	*node;

	node = (struct s_node*)malloc(sizeof(struct s_node));
	if (!node)
		return (NULL);
	node->c = c;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void			createList(struct s_node **list, char c)
{
	struct s_node	*node;

	if (!*list)
	{
		*list = createElem(c);
		(*list)->next = *list;
		(*list)->prev = *list;
	}
	else
	{
		node = createElem(c);
		node->next = *list;
		node->prev = (*list)->prev;
		(*list)->prev->next = node;
		(*list)->prev = node;
	}
}

char			*precious(int *text, int size)
{
	struct s_node	*list;
	char			*str;
	int				i;
	int				j;

	if (size <= 0)
		return (NULL);
	str = (char*)malloc(sizeof(char) * (size + 1));
	i = -1;
	while (++i < 80)
		createList(&list, CS[i]);
	i = -1;
	while (++i < size)
	{
		if (text[i] == 0)
			str[i] = list->c;
		else
		{
			if (text[i] < 0)
				text[i] = text[i] % 80 + 80;
			j = -1;
			while (++j < text[i])
				list = list->next;
			str[i] = list->c;
		}
	}
	return (str);
}
