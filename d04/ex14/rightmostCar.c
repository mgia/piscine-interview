/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rightmostCar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 10:02:05 by mtan              #+#    #+#             */
/*   Updated: 2018/05/01 10:08:43 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int rightmostCar(unsigned int parkingRow)
{
	int count = 0;
	if (!parkingRow)
		return (-1);
	while (!(parkingRow & 1))
	{
		count++;
		parkingRow >>= 1;
	}
	return (count);
}
