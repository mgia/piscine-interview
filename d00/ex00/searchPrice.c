/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 09:55:39 by mtan              #+#    #+#             */
/*   Updated: 2018/04/23 09:55:39 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

int  searchPrice(struct s_art **arts, char *name)
{
	int	i;

	i = 0;
	while (arts[i] && strcmp(name, arts[i]->name))
		i++;
	if (arts[i])
		return (arts[i]->price);
	return (-1);
}
