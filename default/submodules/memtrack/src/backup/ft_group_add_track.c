/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group_add_track.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:40:10 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:46:18 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_group_add_track(t_group **group, t_track *track)
{
	if (!group || !*group || !track)
		return ;
	ft_track_add_back(&(*group)->head, track);
}
