/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NthLastCity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:37:00 by mtan              #+#    #+#             */
/*   Updated: 2018/04/25 20:52:40 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*NthLastCity(struct s_city *city, int n)
{
	struct s_city	*curr;
	int				offset;

	curr = city;
	offset = -n;
	while (city)
	{
		if (offset > 0)
			curr = curr->next;
		offset++;
		city = city->next;
	}
	if (curr && offset)
		return (curr->name);
	return (0);
}
