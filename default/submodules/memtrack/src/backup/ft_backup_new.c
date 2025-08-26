/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:37:27 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 21:15:21 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_new - Crea una nueva estructura de backup.
 * @slot_count: Número de slots en el backup.
 * 
 * Esta función crea una nueva estructura de backup y la inicializa con el
 * Retorna un puntero a la nueva estructura de backup inicializada.
 * si slot_count es 0 o menos, se crea un backup vacío, sin slots.
 */

t_backup	*ft_backup_new(size_t slot_count)
{
	t_backup	*backup;

	backup = ft_calloc(1, sizeof(t_backup));
	if (!backup)
		return (NULL);
	if (slot_count > 0)
		backup->slots = ft_slot_array_new(slot_count);
	if (!backup->slots)
		return (backup);
	backup->slot_count = slot_count;
	return (backup);
}
