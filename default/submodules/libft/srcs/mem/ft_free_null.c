/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_null.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:17:27 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/05 10:06:13 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * free_null - Libera la memoria de un puntero y lo establece a NULL.
 * @ptr: Doble puntero al elemento a liberar.
 *
 * Esta función verifica si el puntero no es NULL y si apunta a un bloque de
 * memoria asignado. Si es así, libera la memoria y establece el puntero a NULL

 * para evitar referencias colgantes.
 */

void	free_null(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
