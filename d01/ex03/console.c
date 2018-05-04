/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:54:41 by mtan              #+#    #+#             */
/*   Updated: 2018/04/25 16:54:41 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_stack	*initStack(void)
{
	struct s_stack	*stack;

	stack = (struct s_stack*)malloc(sizeof(struct s_stack));
	stack->item = NULL;
	return (stack);
}

int				pop(struct s_stack *stack)
{
	struct s_item	*node;
	int				idx;

	node = stack->item;
	idx = node->idx;
	stack->item = stack->item->next;
	free(node);
	return (idx);
}

void			push(struct s_stack *stack, int idx)
{
	struct s_item	*temp = malloc(sizeof(struct s_item));

	temp->idx = idx;
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

char			*console(void)
{
	struct s_stack	*stack = initStack();
	char			*msg = calloc(1, 256);
	char			*line = NULL;
	size_t			len = 255;
	ssize_t			word;
	int				i = 0;
	int				idx;

	while (1)
	{
		printf("?: ");
		word = getline(&line, &len, stdin);
		if (!strncmp(line, "UNDO", 4))
		{
			if (!stack->item)
				continue ;
			idx = pop(stack);
			memset(&msg[idx], '\0', 255 - idx);
			i = idx;
		}
		else if (!strncmp(line, "SEND", 4))
		{
			while (stack->item)
				pop(stack);
			free(stack);
			return (msg);
		}
		else
		{
			push(stack, i);
			strncat(msg, line, word - 1);
			strncat(msg, " ", 1);
			i += word;
		}
		printf("%s\n", msg);
	}
	return (NULL);
}
