/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxSW.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 14:41:27 by mtan              #+#    #+#             */
/*   Updated: 2018/05/03 14:41:44 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "header.h"

struct s_deque *dequeInit(void)
{
	struct s_deque	*q = malloc(sizeof(struct s_deque));
	q->first = NULL;
	q->last = NULL;
	return (q);
}

struct s_dequeNode *nodeInit(int value)
{
	struct s_dequeNode *tmp = malloc(sizeof(struct s_dequeNode));
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void pushFront(struct s_deque *deque, int value)
{
	struct s_dequeNode *new = nodeInit(value);
	new->next = deque->first;
	if (deque->first)
		deque->first->prev = new;
	deque->first = new;
	if (!deque->last)
		deque->last = new;
}

void pushBack(struct s_deque *deque, int value)
{
	struct s_dequeNode *new = nodeInit(value);
	new->prev = deque->last;
	if (deque->last)
		deque->last->next = new;
	deque->last = new;
	if (!deque->first)
		deque->first = new;
}
int popFront(struct s_deque *deque)
{
	struct s_dequeNode	*tmp = deque->first;
	int					value = tmp->value;
	if (!tmp)
		return (INT_MIN);
	deque->first = tmp->next;
	if (!deque->first)
		deque->last = NULL;
	else
		deque->first->prev = NULL;
	free(tmp);
	return (value);
}

int popBack(struct s_deque *deque)
{
	struct s_dequeNode	*tmp = deque->last;
	int					value = tmp->value;
	if (!tmp)
		return (INT_MIN);
	deque->last = tmp->prev;
	if (!deque->last)
		deque->first = NULL;
	else
		deque->last->next = NULL;
	free(tmp);
	return (value);
}

int				empty(struct s_deque *q)
{
	return (!(q->first && q->last));
}

int				peekFront(struct s_deque *deque)
{
	if (!deque || !deque->first)
		return INT_MIN;
	return (deque->first->value);
}

int				peekBack(struct s_deque *deque)
{
	if (!deque || !deque->last)
		return INT_MIN;
	return (deque->last->value);
}

struct s_max	*maxSlidingWindow(int *arr, int n, int k)
{
	struct s_deque	*q = dequeInit();
	struct s_max	*res = malloc(sizeof(struct s_max));
	int				len = n - k + 1;
	int				i;

	res->max = calloc(len, sizeof(int));
	res->length = len;
	for (i = 0; i < k; i++)
	{
		while (!empty(q) && peekBack(q) != INT_MIN && arr[peekBack(q)] < arr[i])
			popBack(q);
		pushBack(q, i);
	}
	for ( ; i < n; i++)
	{
		res->max[i - k] = arr[peekFront(q)];
		while (q->first && peekFront(q) != INT_MIN && peekFront(q) <= i - k)
			popFront(q);
		while (q->last && peekBack(q) != INT_MIN && arr[peekBack(q)] < arr[i])
			popBack(q);
		pushBack(q, i);
	}
	res->max[n - k] = arr[popFront(q)];
	return (res);
}
