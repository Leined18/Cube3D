/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:38:23 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/26 12:42:30 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned_fd(unsigned long n, int fd)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789";
	if (n > (ft_strlen(base) - 1))
		len += ft_putunsigned_fd(n / ft_strlen(base), fd);
	len += ft_putchar_fd(*(base + (n % ft_strlen(base))), fd);
	return (len);
}
/*
int	main(void)
{
	unsigned long number = 429; // Example number
	int printed_chars;

	printed_chars = ft_putunsigned(number);
	ft_putchar('\n');
	ft_putstr("Printed characters: ");
	ft_putnbr(printed_chars);
	ft_putchar('\n');

	return (0);
}*/
