/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtlast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:00:48 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:31:19 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtlast - Devuelve el último nodo de la lista.
 * * @node: Doble puntero al primer nodo de la lista.
 * @move: Indica si se debe mover el puntero al último nodo.
 *
 * Esta función recorre la lista enlazada de nodos y devuelve el último nodo.
 */

t_mt	*ft_mtlast(t_mt **node, bool move)
{
	t_mt	*last;

	if (!node || !*node)
		return (NULL);
	last = *node;
	while (last)
		last = last->next;
	if (move)
		*node = last;
	return (last);
}
