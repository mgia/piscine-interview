/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 17:24:47 by mtan              #+#    #+#             */
/*   Updated: 2018/04/30 17:26:01 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>

int carPosition(unsigned int parkingRow)
{
	if (!parkingRow || (parkingRow & parkingRow - 1))
		return (-1);
	return (log2(parkingRow));
}
