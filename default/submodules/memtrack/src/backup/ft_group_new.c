/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:32:04 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:42:54 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_group	*ft_group_new(const char *group_id)
{
	t_group	*new_group;

	if (!group_id)
		return (NULL);
	new_group = ft_calloc(1, sizeof(t_group));
	if (!new_group)
		return (NULL);
	new_group->id = ft_strdup(group_id);
	if (!new_group->id)
	{
		free(new_group);
		return (NULL);
	}
	return (new_group);
}
