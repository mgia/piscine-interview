/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sinkIsland.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 11:33:26 by mtan              #+#    #+#             */
/*   Updated: 2018/05/02 11:33:26 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

void sinkIsland(int **map, int row, int col)
{
	if (row < 0 || col < 0 || map[row] == 0 || map[row][col] == -1)
		return ;
	if (map[row][col] == 0)
		return ;
	map[row][col] = 0;
	sinkIsland(map, row + 1, col);
	sinkIsland(map, row - 1, col);
	sinkIsland(map, row, col + 1);
	sinkIsland(map, row, col - 1);
}
