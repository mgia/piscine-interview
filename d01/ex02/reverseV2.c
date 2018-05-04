/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 12:04:52 by mtan              #+#    #+#             */
/*   Updated: 2018/04/25 12:04:54 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct s_stack	*stackInit(void)
{
	struct s_stack	*stack;

	stack = (struct s_stack*)malloc(sizeof(struct s_stack));
	stack->item = NULL;
	return (stack);
}

void	*pop(struct s_stack *stack)
{
	struct s_item	*node;
	char			*c;

	if (!stack || !stack->item)
		return (NULL);

	node = stack->item;
	c = node->word;
	stack->item = stack->item->next;
	free(node);
	return (c);
}

void	push(struct s_stack *stack, char *word)
{
	struct s_item	*temp;

	if (!word)
		return ;
	temp = malloc(sizeof(struct s_item));
	temp->word = word;
	if (!stack->item)
	{
		temp->next = NULL;
		stack->item = temp;
	}
	else
	{
		temp->next = stack->item;
		stack->item = temp;
	}
}

void printReverseV2(struct s_node *lst)
{
	struct s_stack *stack = stackInit();
	struct s_node  *head = lst;

	while (lst)
	{
		push(stack, lst->word);
		lst = lst->next;
	}
	while (head)
	{
		printf("%s", pop(stack));
		printf("%c", head->next ? ' ' : '\n');
		head = head->next;
	}
}
