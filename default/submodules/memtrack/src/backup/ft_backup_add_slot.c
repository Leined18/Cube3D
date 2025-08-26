/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_add_slot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:33:58 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:44:54 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_hash - Calcula el hash de un nodo.
 * @node: Puntero al nodo.
 *
 * Retorna el hash del nodo.
 */

size_t	ft_hash(t_mt *node)
{
	size_t	hash;
	size_t	i;

	if (!node || !node->id)
		return (0);
	hash = 0;
	i = 0;
	while (node->id[i])
	{
		hash += node->id[i];
		i++;
	}
	return (hash);
}

/**
 * ft_backup_add_slot - Agrega un nodo a la lista de seguimiento del backup.
 * @backup: Doble puntero a la estructura de backup.
 * @node: Puntero al nodo a agregar.
 *
 */

void	ft_backup_add_slot(t_backup **backup, t_slot *slot)
{
	t_backup	*backup_tmp;

	if (!backup || !*backup || !slot)
		return ;
	backup_tmp = *backup;
	if (backup_tmp->slots)
		ft_slot_hash_add(backup_tmp->slots, backup_tmp->slot_count, slot);
}
