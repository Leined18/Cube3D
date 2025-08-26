/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:57:08 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:46:56 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_backup_delete(t_backup **backup, const char *key)
{
	t_mt	*target;

	if (!backup || !*backup || !key || ft_strlen(key) == 0)
		return ;
	target = ft_backup_search(backup, key);
	ft_backup_remove(backup, target, true);
}
