/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:47:01 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:47:03 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_backup_clear - Libera la memoria de la estructura de backup.
 * @backup: Doble puntero a la estructura de backup.
 *
 * Esta función libera la memoria ocupada por la estructura de backup y sus
 * elementos. Se asegura de liberar todos los slots y el tracker asociado.
 */

int	ft_backup_clear(t_backup **backup)
{
	if (!backup || !*backup)
		return (0);
	if ((*backup)->slots)
		ft_slot_clear((*backup)->slots, (*backup)->slot_count, false);
	if ((*backup)->groups)
		ft_group_clear(&(*backup)->groups, true);
	return (free_null((void **)backup), 1);
}
