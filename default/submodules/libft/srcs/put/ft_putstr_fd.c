/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:02:49 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/26 12:47:40 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		return (write(fd, "(null)", 6));
	len = ft_strlen(s);
	return (write(fd, s, len));
}
/*
int	main(void) {
	// Write C code here
	char c[] = "Piano";
	int i = 0;

	while (i < sizeof(int))
	{
		ft_putstr_fd(c,1);
		ft_putchar_fd(' ', 1);
		i++;
	}

	return (0);
}*/
