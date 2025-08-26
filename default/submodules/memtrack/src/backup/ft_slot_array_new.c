/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slot_array_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:07:58 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:41:59 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/*
 * ft_slot_array_new - Crea un nuevo array de slots.
 * @slot_count: Número de slots a crear.
 *
 * Retorna un puntero al array de slots o NULL si falla la asignación.
 */

t_slot	**ft_slot_array_new(size_t slot_count)
{
	t_slot	**slots;

	slots = ft_calloc(slot_count, sizeof(t_slot *));
	if (!slots)
		return (NULL);
	return (slots);
}
