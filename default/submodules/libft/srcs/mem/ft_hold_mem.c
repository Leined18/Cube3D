/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hold_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 08:54:11 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:56:17 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hold_mem(size_t ac, ...)
{
	va_list			ap;
	void			*ptr;
	static t_list	*list = NULL;

	va_start(ap, ac);
	while (ac-- > 0)
	{
		ptr = va_arg(ap, void *);
		if (ptr)
		{
			ft_lstadd_back(&list, ft_lstnew(ptr));
			ptr = NULL;
		}
	}
	va_end(ap);
}
