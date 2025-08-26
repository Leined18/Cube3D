/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:03:22 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/26 12:10:07 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	len;

	len = ft_putstr_fd(s, fd);
	len += ft_putchar_fd('\n', fd);
	return (len);
}
/*
int	main(void) {
	// Write C code here
	char c[] = "Ayuda";
	int i = 0;

	while (i < sizeof(short int))
	{
		ft_putendl_fd(c,1);
		i++;
	}

	return (0);
}*/
