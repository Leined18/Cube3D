/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_remove_slot.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:53:06 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:46:41 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_remove_slot - Elimina una ranura del backup.
 * @backup: Doble puntero a la estructura de backup.
 * @slot: Puntero a la ranura a eliminar.
 * @free_slot: Booleano que indica si se debe liberar la memoria de la ranura.
 *
 * Esta función elimina una ranura del backup y libera su memoria.
 * Se asegura de eliminar la ranura de la lista de ranuras y liberar su memoria.
 */

int	ft_backup_remove_slot(t_backup **backup, t_mt *target, bool free_slot)
{
	size_t	i;

	if (!backup || !(*backup)->slots || !target)
		return (0);
	i = 0;
	while (i < (*backup)->slot_count)
	{
		ft_slot_remove(&(*backup)->slots[i], (*backup)->slot_count, target,
			free_slot);
		i++;
	}
	return (0);
}
