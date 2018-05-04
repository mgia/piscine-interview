/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 17:47:58 by mtan              #+#    #+#             */
/*   Updated: 2018/04/25 17:48:12 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

struct s_tank *initTank(void)
{
	struct s_tank *tank;

	if (!(tank = malloc(sizeof(struct s_tank))))
		return (NULL);
	tank->stacks = NULL;
	tank->n = 0;
	return (tank);
}

void addStack(struct s_tank *tank)
{
	struct s_stack *stack;

	if (!tank)
		return ;
	tank->n++;
	tank->stacks = realloc(tank->stacks, tank->n * sizeof(struct s_stack));
	stack = malloc(sizeof(struct s_stack));
	stack->elem = NULL;
	stack->sum = 0;
	tank->stacks[tank->n - 1] = stack;
}

void stackPush(struct s_stack *stack, int energy)
{
	struct s_elem *new;

	if (!stack)
		return ;
	new = malloc(sizeof(struct s_elem));
	new->energy = energy;
	new->next = stack->elem;
	stack->elem = new;
	stack->sum += energy;
}

void tankPush(struct s_tank *tank, int energy)
{
	if (!tank)
		return ;
	if ((energy && !tank->n) || tank->stacks[tank->n - 1]->sum + energy > 1000)
		addStack(tank);
	stackPush(tank->stacks[tank->n - 1], energy);
}

int stackPop(struct s_stack *stack)
{
	struct s_elem	*node;
	int				energy;

	node = stack->elem;
	energy = node->energy;
	stack->elem = node->next;
	free(node);
	return (energy);
}

void removeStack(struct s_tank *tank)
{
	if (!tank)
		return ;

	tank->n--;
	if (!tank->n)
	{
		free(tank->stacks);
		tank->stacks = NULL;
	}
	else
		tank->stacks = realloc(tank->stacks, tank->n * sizeof(struct s_stack));
}

int tankPop(struct s_tank *tank)
{
	int	energy;

	if (!tank || !tank->n)
		return (0);
	energy = stackPop(tank->stacks[tank->n - 1]);
	if (!tank->stacks[tank->n - 1]->elem)
		removeStack(tank);
	return (energy);
}
