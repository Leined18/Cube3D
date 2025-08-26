/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:20:05 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:31:15 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtnew - Crea un nuevo nodo de tipo t_mt.
 * @group_id: Clave del nodo.
 * @backup: Puntero a la estructura de backup donde se agregará el nodo.
 * si existe un backup, se agrega el nodo a la lista de seguimiento del backup.
 */

t_mt	*ft_mtnew(const char *group_id, const char *id)
{
	t_mt		*node;
	t_backup	*backup;

	if (!group_id)
		return (NULL);
	node = ft_calloc(1, sizeof(t_mt));
	if (!node)
		return (NULL);
	node->group_id = ft_strdup(group_id);
	if (!node->group_id)
		return (free(node), NULL);
	node->id = ft_strdup(id);
	if (!node->id)
		return (free(node->group_id), free(node), NULL);
	backup = ft_backup_static(0, false, false);
	if (backup)
		ft_backup_add(&backup, node);
	return (node);
}
