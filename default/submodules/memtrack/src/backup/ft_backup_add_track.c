/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_add_track.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:46:24 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:44:44 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_backup_add_track(t_backup **backup, t_track *track)
{
	t_group	*group;

	if (!backup || !*backup || !track)
		return ;
	if (!(*backup)->groups)
		(*backup)->groups = ft_group_new(track->group_id);
	group = ft_group_search((*backup)->groups, track->group_id);
	if (!group)
		ft_group_add_track(&group, track);
	else
	{
		group = ft_group_new(track->group_id);
		ft_group_add_back(&(*backup)->groups, group);
		ft_group_add_track(&group, track);
	}
}
