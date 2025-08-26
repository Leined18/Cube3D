/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slot_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:27:36 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 11:07:13 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int	ft_slot_remove(t_slot **slots, size_t slot_count, t_mt *target,
		bool free_target)
{
	int		i;
	t_slot	*cur;

	if (!slots || slot_count == 0 || !target)
		return (0);
	i = -1;
	while (++i < (int)slot_count)
	{
		cur = slots[i];
		while (cur)
		{
			if (cur->node == target)
			{
				slots[i] = cur->top;
				if (free_target)
					ft_slot_free(&cur, true);
				return (1);
			}
			cur = cur->top;
		}
	}
	return (0);
}
