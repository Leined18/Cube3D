/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtdelete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:02:46 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:38:18 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtdelete(const char *key)
{
	t_backup	*backup;

	if (!key || ft_strlen(key) == 0)
		return ;
	backup = ft_backup_static(0, false, false);
	if (!backup)
		return ;
	ft_backup_delete(&backup, key);
}
