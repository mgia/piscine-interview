/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftmostCar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 09:48:51 by mtan              #+#    #+#             */
/*   Updated: 2018/05/01 10:07:47 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int leftmostCar(unsigned int parkingRow)
{
	int count = 0;
	if (!parkingRow)
		return (-1);
	while (1 < parkingRow)
	{
		count++;
		parkingRow >>= 1;
	}
	return (count);
}
