/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:04:36 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/26 12:55:08 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (n < 0)
		return (ft_putchar_fd('-', fd) + ft_putnbr_fd(-n, fd));
	else if (n >= 10)
		return (ft_putnbr_fd(n / 10, fd) + ft_putnbr_fd(n % 10, fd));
	else
		return (ft_putchar_fd(n + '0', fd));
}
/*
int	main(void) {
	// Write C code here
	int i = 19999;

	ft_putnbr_fd(NULL,1);

	return (0);
}*/
