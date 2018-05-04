/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correctSong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 11:04:48 by mtan              #+#    #+#             */
/*   Updated: 2018/05/01 11:29:38 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	correctSong(struct s_bit *bit, int l, int row, int col, int dist)
{
	if (row < l)
		for (int i = row; i < row + dist; i++)
			bit->arr[i] |= 1 << col;
}
