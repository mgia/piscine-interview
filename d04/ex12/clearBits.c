/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearBits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 09:44:10 by mtan              #+#    #+#             */
/*   Updated: 2018/05/01 22:24:26 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

unsigned int clearBits(unsigned int parkingRow, int n)
{
	return (parkingRow & ~((1 << n) - 1));	
}