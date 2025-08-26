/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_static.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:09:49 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:50:43 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_static - Crea un backup estático de un nodo t_mt.
 * @slot_count: Número de ranuras en el backup.
 * @new booleano que determina si creas un nuevo backup mas el @slotcount
 * @clear booleano que determina si limpias el backup, new
	+ clear reinicia el backup
sin new, solo limpia y retorna nulo.
 * Retorna:
 *   Un puntero a la estructura de backup creada.
 */

t_backup	*ft_backup_static(size_t slot_count, bool new, bool clear)
{
	static t_backup	*backup = NULL;

	if (backup && !new && !clear && (slot_count == backup->slot_count
			|| !slot_count))
		return (backup);
	if (!backup && slot_count > 0 && new && !clear)
		backup = ft_backup_new(slot_count);
	else if (backup && new && clear)
	{
		ft_backup_clear(&backup);
		return (ft_backup_static(slot_count, true, false));
	}
	else if (backup && clear && !new)
		return (ft_backup_clear(&backup), NULL);
	else if (backup && !clear && new && slot_count > 0)
	{
		ft_backup_slot_update(&backup, slot_count);
		return (backup);
	}
	return (backup);
}
