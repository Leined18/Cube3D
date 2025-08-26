/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:36:32 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:31:27 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	*ft_mtget_id(t_mt *mt)
{
	if (!mt)
		return (NULL);
	return (mt->id);
}

void	ft_mtset_id(t_mt *mt, void *id)
{
	if (!mt)
		return ;
	if (mt->id)
		free(mt->id);
	mt->id = ft_strdup(id);
}
