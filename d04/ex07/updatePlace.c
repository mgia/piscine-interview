/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatePlace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 12:02:07 by mtan              #+#    #+#             */
/*   Updated: 2018/04/30 13:39:13 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int updatePlace(unsigned int parkingRow, int pos, int value)
{
	return ((parkingRow & ~(1 << pos)) | (value << pos));
}
