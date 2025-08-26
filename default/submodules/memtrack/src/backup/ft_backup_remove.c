/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:28:23 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:44:20 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_remove - Elimina un nodo de la lista de seguimiento del backup.
 * @backup: Doble puntero a la estructura de backup.
 * @target: Puntero al nodo a eliminar.
 *
 * Esta función elimina un nodo de la lista de seguimiento del backup y libera
 * su memoria. Se asegura de eliminar el nodo de la lista y liberar su memoria.
 */

void	ft_backup_remove(t_backup **backup, t_mt *target, bool free_target)
{
	if (!backup || !target)
		return ;
	if (!ft_slot_remove((*backup)->slots, (*backup)->slot_count, target,
			free_target))
		return ;
	(*backup)->item_count--;
}
