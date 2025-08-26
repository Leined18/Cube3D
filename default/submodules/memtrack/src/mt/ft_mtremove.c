/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtremove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:30:43 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:31:13 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtremove - Elimina un nodo de la lista enlazada.
 * @node: Puntero al nodo a eliminar.
 * return: if the node was removed successfully, otherwise returns 0.
 */

int	ft_mtremove(t_mt **head, t_mt *target, bool free)
{
	t_mt	*current;

	if (!head || !*head || !target)
		return (0);
	current = ft_mtfind(*head, target);
	if (!current)
		return (0);
	if (current->prev)
		current->prev->next = current->next;
	else
		*head = current->next;
	if (current->next)
		current->next->prev = current->prev;
	if (free)
		ft_mtfree(current);
	else
	{
		target->next = NULL;
		target->prev = NULL;
	}
	return (1);
}
