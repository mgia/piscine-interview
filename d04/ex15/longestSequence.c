/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longestSequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 10:09:31 by mtan              #+#    #+#             */
/*   Updated: 2018/05/01 10:48:12 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int longestSequence(unsigned int parkingRow)
{
	int count = 0;
	while (parkingRow)
	{
		count++;
		parkingRow &= parkingRow << 1;
	}
	return (count);	
}
