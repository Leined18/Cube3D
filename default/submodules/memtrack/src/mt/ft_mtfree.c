/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:37:57 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/21 11:13:33 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static void	free_element(void **element, void (*free_func)(void *))
{
	if (element && *element)
	{
		if (free_func)
			free_func(*element);
		else
			free_null(element);
		*element = NULL;
	}
}

/**
 * ft_free - Libera la memoria de un nodo t_mt.
 * @mt: Puntero al nodo a liberar.
 *
 * Esta función libera la memoria ocupada por el nodo t_mt y sus elementos
 * asociados.
 * Se asegura de liberar la clave, los datos y los enlaces del nodo.
 * esta tambien se usa en lstclear para liberar el tracker de backup.
 */

void	ft_mtfree(void *mt)
{
	t_mt	*node;

	if (!mt)
		return ;
	node = (t_mt *)mt;
	if (node->backup)
	{
		node->backup = NULL;
		ft_backup_delete(&node->backup, node->id);
		return ;
	}
	if (node->group_id)
		free_element((void **)&node->group_id, NULL);
	if (node->id)
		free_element((void **)&node->id, NULL);
	if (node->data && node->data_free)
		free_element((void **)&node->data, node->data_free);
	if (node->addon && node->addon_free)
		free_element((void **)&node->addon, node->addon_free);
	free(node);
}
