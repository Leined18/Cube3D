/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:22:30 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:53:18 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, void *data_ref)
{
	t_list	*current;

	if (!lst || !data_ref)
		return (NULL);
	current = lst;
	while (current)
	{
		if (current->content == data_ref)
			return (current);
		current = current->next;
	}
	return (NULL);
}
