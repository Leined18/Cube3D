/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtkey.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:32:50 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:33:45 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

char	*ft_mtget_group_id(t_mt *mt)
{
	if (!mt)
		return (NULL);
	return (mt->group_id);
}

void	ft_mtset_group_id(t_mt *mt, void *group_id)
{
	if (!mt || !group_id)
		return ;
	if (mt->group_id)
		free(mt->group_id);
	mt->group_id = ft_strdup(group_id);
}

int	ft_mtgroup_id_cmp(const t_mt *mt1, const char *group_id)
{
	if (!mt1 || !mt1->group_id || !group_id)
		return (0);
	return (ft_strncmp(mt1->group_id, group_id, ft_strlen(mt1->group_id)) == 0);
}
