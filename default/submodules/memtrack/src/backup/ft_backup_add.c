/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:48:25 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:47:17 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_add - Agrega un nodo a la lista de seguimiento del backup.
 * @backup: Doble puntero a la estructura de backup.
 * @node: Puntero al nodo a agregar.
 *
 */

void	ft_backup_add(t_backup **backup, t_mt *node)
{
	t_group	*group;

	if (!backup || !*backup || !node)
		return ;
	if (!node->group_id || !node->id)
		return ;
	group = ft_group_search((*backup)->groups, node->group_id);
	if (!group)
	{
		group = ft_group_new(node->group_id);
		if (!group)
			return ;
		ft_group_add_back(&(*backup)->groups, group);
	}
	ft_group_add_mt(&group, node);
	ft_backup_add_slot_mt(backup, node);
	(*backup)->item_count++;
}
