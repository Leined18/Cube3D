/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtaddon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:40:21 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:34:13 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	*ft_mtget_addon(t_mt *mt)
{
	if (!mt)
		return (NULL);
	return (mt->addon);
}

void	*ft_mtget_addon_free(t_mt *mt)
{
	if (!mt)
		return (NULL);
	return (mt->addon_free);
}

void	ft_mtset_addon(t_mt *mt, void *addon)
{
	if (!mt)
		return ;
	if (mt->addon && mt->addon_free)
		mt->addon_free(mt->addon);
	mt->addon = addon;
}

void	ft_mtset_addon_free(t_mt *mt, void *addon_free)
{
	if (!mt)
		return ;
	mt->addon_free = addon_free;
}
