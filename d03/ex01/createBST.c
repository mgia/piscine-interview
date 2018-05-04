/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 15:55:23 by mtan              #+#    #+#             */
/*   Updated: 2018/04/27 15:55:23 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

struct s_node *bst(int *arr, int left, int right)
{
	if (left > right)
		return NULL;
	int mid = (left + right) / 2;
	struct s_node *root = malloc(sizeof(struct s_node));
	root->value = arr[mid];
	root->left = bst(arr, left, mid - 1);
	root->right = bst(arr, mid + 1, right);
	return root;

}

struct s_node *createBST(int *arr, int n)
{
	return bst(arr, 0, n - 1);
}
