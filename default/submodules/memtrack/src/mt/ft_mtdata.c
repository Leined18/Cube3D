/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtdata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:38:42 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:34:02 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	*ft_mtget_data(t_mt *mt)
{
	if (!mt)
		return (NULL);
	return (mt->data);
}

void	*ft_mtget_data_free(t_mt *mt)
{
	if (!mt)
		return (NULL);
	return (mt->data_free);
}

void	ft_mtset_data(t_mt *mt, void *data)
{
	if (!mt)
		return ;
	if (mt->data_free && mt->data)
		mt->data_free(mt->data);
	mt->data = data;
}

void	ft_mtset_data_free(t_mt *mt, void *data_free)
{
	if (!mt)
		return ;
	mt->data_free = data_free;
}
