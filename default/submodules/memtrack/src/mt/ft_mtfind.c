/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtfind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:07:49 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:31:52 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	*ft_mtfind(t_mt *node, t_mt *target)
{
	t_mt	*current;
	t_mt	*found;

	if (!node || !target)
		return (NULL);
	found = NULL;
	current = node;
	while (current)
	{
		if (current == target)
		{
			found = current;
			break ;
		}
		current = current->next;
	}
	return (found);
}
