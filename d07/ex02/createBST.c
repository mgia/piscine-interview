/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:23:41 by mtan              #+#    #+#             */
/*   Updated: 2018/05/03 18:23:43 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

struct s_node *nodeInit(int value)
{
	struct s_node *new = malloc(sizeof(struct s_node));
	new->value = value;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

struct s_node *recurse(int *arr, int l, int r)
{
	if (l > r)
		return (NULL);
	int mid = (l + r) / 2;
	struct s_node *root = nodeInit(arr[mid]);
	root->left = recurse(arr, l, mid - 1);
	root->right = recurse(arr, mid + 1, r);
	return (root);
}

struct s_node *createBST(int *arr, int n)
{
	return (recurse(arr, 0, n - 1));
}
