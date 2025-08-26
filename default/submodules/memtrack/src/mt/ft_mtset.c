/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:43:51 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:31:55 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtset - Establece un nodo en la lista enlazada.
 * @key: Clave del nodo a establecer.
 * @data: Datos del nodo a establecer.
 *
 * Esta función establece un nodo en la lista enlazada, creando un nuevo nodo si
 * no existe uno con la clave proporcionada. Si el nodo ya existe, actualiza sus
 * datos y lo vincula al backup.
 */

int	ft_mtset(const char *key, void *data, void (*set_func)(t_mt *, void *))
{
	t_mt	*node;

	if (!key || !set_func || !data)
		return (0);
	node = ft_mtget(key);
	if (!node)
		return (0);
	set_func(node, data);
	return (1);
}
