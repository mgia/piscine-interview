/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 11:02:56 by mtan              #+#    #+#             */
/*   Updated: 2018/04/23 11:03:22 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdlib.h>
#define PRIME 33

size_t			hash(char *input)
{
	size_t	hash = 0;

	while (*input)
		hash = hash * PRIME + (unsigned char)(*input++);
	return (hash);
}

struct s_dict	*dictInit(int capacity)
{
	struct s_dict	*dict;

	if (capacity < 1)
		return (NULL);
	if (!(dict = (struct s_dict*)malloc(sizeof(struct s_dict))))
		return (NULL);
	if (!(dict->items = (struct s_item**)calloc(capacity, sizeof(struct s_item*))))
		return (NULL);
	dict->capacity = capacity;
	return (dict);
}

int				dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
	struct s_item	*tmp;
	size_t			i;

	i = hash(key) % dict->capacity;
	if (!dict->items[i])
	{
		if (!(dict->items[i] = (struct s_item*)malloc(sizeof(struct s_item))))
			return (0);
		tmp = dict->items[i];
	}
	else
	{
		tmp = dict->items[i];
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (struct s_item*)malloc(sizeof(struct s_item))))
			return (0);
		tmp = tmp->next;
	}
	if (!(tmp->key = strdup(key)))
		return (0);
	tmp->value = value;
	tmp->next = NULL;
	return (1);
}

struct s_art	*dictSearch(struct s_dict *dict, char *key)
{
	struct s_item	*tmp;
	size_t			i;

	i = hash(key) % dict->capacity;
	tmp = dict->items[i];
	while (tmp)
	{
		if (!strcmp(key, tmp->key))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

int				searchPrice(struct s_dict *dict, char *name)
{
	return (dictSearch(dict, name)->price);
}
