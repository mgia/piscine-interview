/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junkFood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 14:05:50 by mtan              #+#    #+#             */
/*   Updated: 2018/05/04 14:05:51 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int					empty(struct s_queue *q)
{
	return (!(q->first && q->last));
}

struct s_node		*getStart(struct s_graph *graph, char *youAreHere)
{
	struct s_node *start = NULL;
	for (int i = 0; graph->places[i]; i++)
	{
		if (strcmp(graph->places[i]->name, youAreHere) == 0)
		{
			start = graph->places[i];
			break ;
		}
	}
	return (start);
}

void	resetVisited(struct s_node *start)
{
	struct s_queue	*q = queueInit();
	struct s_node	*node;

	enqueue(q, start);
	while (!empty(q))
	{
		node = dequeue(q);
		node->visited = 0;
		for (int i = 0; node->connectedPlaces[i]; i++)
			if (node->connectedPlaces[i]->visited == 1)
				enqueue(q, node->connectedPlaces[i]);
	}
}

struct s_sellers	*getSellers(struct s_queue *queue, int dist, int found)
{
	struct s_sellers *res = malloc(sizeof(struct s_sellers));
	res->placeNames = calloc(found + 1, sizeof(char*));
	res->distance = dist;
	for (int i = 0; i < found; i++)
		res->placeNames[i] = dequeue(queue)->name;
	return (res);
}

struct s_sellers	*closestSellers(struct s_graph *graph, char *youAreHere)
{
	struct s_node *start = getStart(graph, youAreHere);
	struct s_node *node;
	struct s_queue *q = queueInit();
	struct s_queue *res = queueInit();
	int dist = 0;
	int found = 0;

	if (!start)
		return (NULL);
	enqueue(q, start);
	enqueue(q, NULL);
	while (!empty(q))
	{
		while ((node = dequeue(q)))
		{
			node->visited = 1;
			if (node->hasCerealBar)
			{
				found++;
				enqueue(res, node);
			}
			else
			{
				for (int i = 0; node->connectedPlaces[i]; i++)
				{
					if (node->connectedPlaces[i]->visited == 0)
					{
						node->connectedPlaces[i]->visited = 1;
						enqueue(q, node->connectedPlaces[i]);
					}
				}
			}
		}
		enqueue(q, NULL);
		if (found)
			break ;
		dist++;
	}
	resetVisited(start);
	return (getSellers(res, dist, found));
}
