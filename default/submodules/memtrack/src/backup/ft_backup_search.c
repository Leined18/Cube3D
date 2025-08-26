/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:46:31 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:46:33 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_hash_str - Calcula el hash de una cadena.
 * @str: Cadena a hashear.
 *
 */

size_t	ft_hash_str(const char *str)
{
	size_t	hash;
	size_t	i;

	if (!str)
		return (0);
	hash = 0;
	i = 0;
	while (str[i])
	{
		hash += str[i];
		i++;
	}
	return (hash);
}

/**
 * ft_backup_search - Obtiene un nodo de la lista de seguimiento del backup.
 * @backup: Doble puntero a la estructura de backup.
 * @id: Clave del nodo a buscar.
 *
 * Retorna el nodo encontrado o NULL si no se encuentra.
 */

t_mt	*ft_backup_search(t_backup **backup, const char *id)
{
	t_mt	*found;

	if (!backup || !*backup || !id || ft_strlen(id) == 0)
		return (NULL);
	found = NULL;
	found = ft_slot_search_mt((*backup)->slots, (*backup)->slot_count, id);
	if (found)
		return (found);
	found = ft_group_search_mt((*backup)->groups, id);
	if (found)
		return (found);
	return (NULL);
}
