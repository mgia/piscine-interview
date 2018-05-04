/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 11:43:26 by mtan              #+#    #+#             */
/*   Updated: 2018/04/27 11:43:26 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>
#include <stdlib.h>
#include <limits.h>

// struct s_node {
// 	int value;
// 	struct s_node *right;
// 	struct s_node *left;
// };
//
// struct s_info {
// 	int min;        // the minimum value in the tree
// 	int max;        // the max value in the tree
// 	int elements;   // the number of nodes in the tree
// 	int height;     // the height of the tree
// 	int isBST;      // 0 = FALSE, 1 = TRUE
// 	int isBalanced; // 0 = FALSE, 1 = TRUE
// };

int				min(struct s_node *root)
{
	if (!root)
		return (INT_MAX);
	return (fmin(root->value, fmin(min(root->left), min(root->right))));
}

int				max(struct s_node *root)
{
	if (!root)
		return (INT_MIN);
	return (fmax(root->value, fmax(max(root->left), max(root->right))));
}

int				count(struct s_node *root)
{
	if (!root)
		return (0);
	return (count(root->left) + count(root->right) + 1);
}

int				height(struct s_node *root)
{
	if (!root || (!root->left && !root->right))
		return (0);
	return (1 + fmax(height(root->left), height(root->right)));
}

int				depth(struct s_node *root)
{
	if (!root)
		return (0);
	return (1 + fmax(depth(root->left), depth(root->right)));
}

int				isBST(struct s_node *root)
{
	if (!root)
		return (1);
	else if (root->left && root->left->value > root->value)
		return (0);
	else if (root->right && root->right->value <= root->value)
		return (0);
	return (isBST(root->left) && isBST(root->right));
}

int				isBalanced(struct s_node *root)
{
	if (!root)
		return (1);
	if (abs(depth(root->left) - depth(root->right)) <= 1
		&& isBalanced(root->left)
		&& isBalanced(root->right))
		return (1);
	return (0);
}

struct s_info   getInfo(struct s_node *root)
{
	struct s_info	info;

	info.min = min(root);
	info.max = max(root);
	info.elements = count(root);
	info.height = height(root);
	info.isBST = isBST(root);
	info.isBalanced = isBalanced(root);
	return (info);
}
