/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 14:27:40 by mtan              #+#    #+#             */
/*   Updated: 2018/04/30 14:32:12 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int carPosition(unsigned int parkingRow)
{
	int pos = 0;
	
	if (!parkingRow || (parkingRow & (parkingRow - 1)))
		return (-1);
	while (parkingRow >>= 1)
		pos++;
	return (pos);
}
