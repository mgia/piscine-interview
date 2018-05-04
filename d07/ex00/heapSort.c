/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapSort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 11:48:26 by mtan              #+#    #+#             */
/*   Updated: 2018/05/03 11:48:33 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

void	swap(struct s_art **arr, int a, int b)
{
	struct s_art *tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;

}

void	heapify(struct s_art **arr, int i, int n)
{
	int max = i;
	if (2 * i + 1 < n && strcmp(arr[2 * i + 1]->name, arr[i]->name) > 0)
		max = 2 * i + 1;
	if (2 * i + 2 < n && strcmp(arr[2 * i + 2]->name, arr[max]->name) > 0)
		max = 2 * i + 2;
	if (max != i)
	{
		swap(arr, i, max);
		heapify(arr, max, n);
	}
}

void	heapSort(struct s_art **masterpiece, int n)
{
	for (int i = n / 2; i >= 0; i--)
		heapify(masterpiece, i, n);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(masterpiece, 0, i);
		heapify(masterpiece, 0, i);
	}
}
