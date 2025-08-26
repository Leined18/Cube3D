/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slot_add_botton.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:08:16 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:42:26 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_slot_add_botton(t_slot **slot, t_slot *node)
{
	if (!slot || !node)
		return ;
	if (!*slot)
	{
		*slot = node;
		return ;
	}
	node->top = *slot;
	*slot = node;
}
