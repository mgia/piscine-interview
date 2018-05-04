/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 23:35:25 by mtan              #+#    #+#             */
/*   Updated: 2018/04/26 23:35:27 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_group {
  int size;
  struct s_group *next;
  struct s_stone *first;
  struct s_stone *last;
}		t_group;

t_group		*newGroup(t_stone *stone)
{
	t_group		*res;

	res = calloc(1, sizeof(t_group));
	res->first = stone;
	res->last = stone;
	res->size = stone->size;
	res->next = 0;
	return (res);
}

void		insertStone(t_group **g, t_stone *s)
{
	t_group		*tmp;

	if (!*g)
		*g = newGroup(s);
	else
	{
		tmp = *g;
		while (tmp->next) {
			if (tmp->size == s->size) {
				tmp->last->next = s;
				tmp->last = s;
				return ;
			}
			tmp = tmp->next;
		}
		tmp->next = newGroup(s);
	}
}

t_group		*getGroups(t_stone *stones)
{
	t_group		*res = NULL;

	while (stones) {
		insertStone(&res, stones);
		stones = stones->next;
	}
	return (res);
}

void		swapGroups(t_group *g1, t_group *g2)
{
	t_stone		*f = g1->first;
	t_stone		*l = g1->last;
	int			s = g1->size;

	g1->first = g2->first;
	g1->last = g2->last;
	g1->size = g2->size;
	g2->first = f;
	g2->last = l;
	g2->size = s;
}

t_stone		*mergeGroups(t_group *g)
{
	t_stone		*res, *tmp;

	res = NULL;
	while (g) {
		if (!res)
			res = g->first;
		else
			tmp->next = g->first;
		tmp = g->last;
		g = g->next;
	}
	tmp->next = NULL;
	return (res);
}

void		deleteGroups(t_group *g)
{
	t_group	*tmp, *next;

	tmp  = g;
	while (tmp) {
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

void		sortStones(struct s_stone **stone)
{
	int			swap;
	t_group		*p1, *p2 = NULL;
	t_group		*groups = getGroups(*stone);

	swap = 1;
	while (swap) {
		swap = 0;
		p1 = groups;
		while (p1->next != p2) {
			if (p1->size > p1->next->size) {
				swapGroups(p1, p1->next);
				swap = 1;
			}
			p1 = p1->next;
		}
		p2 = p1;
	}
	*stone = mergeGroups(groups);
	deleteGroups(groups);
}
