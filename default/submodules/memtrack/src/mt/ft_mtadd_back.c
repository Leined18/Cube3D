/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:35:57 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:35:58 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtadd_back - Añade un nodo al final de la lista t_mt.
 * @head: Doble puntero al primer nodo de la lista.
 * @new_node: Nodo a insertar al final.
 * @backup: Opcional. Si no es NULL, se enlaza el nodo con su sistema de backup.
 *
 * Retorna:
 *   0 si el nodo fue añadido correctamente.
 *  -1 si hay error (punteros nulos o ciclo detectado).
 */

int	ft_mtadd_back(t_mt **head, t_mt *new_node)
{
	t_mt	*current;

	if (!head || !new_node)
		return (-1);
	if (!*head)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next)
		{
			if (current == new_node)
				return (-1);
			current = current->next;
		}
		current->next = new_node;
		new_node->prev = current;
	}
	return (0);
}
