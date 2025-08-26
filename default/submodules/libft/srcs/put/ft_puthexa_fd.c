/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:37:47 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/26 12:17:12 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_fd(unsigned long n, char format, int fd)
{
	char			*base;
	unsigned int	num;
	int				i;
	unsigned int	base_len;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	num = (unsigned int)n;
	base_len = ft_strlen(base);
	if (num > (base_len - 1))
		i += ft_puthexa_fd(num / base_len, format, fd);
	i += ft_putchar_fd(*(base + (num % base_len)), fd);
	return (i);
}

/*
int main(void)
{
    unsigned long number;
    
    number = 30;
    printf("\n%d\n", ft_puthexa(number, 'x'));

    ft_putchar('\n');
    number = 30;
    printf("\n%d\n", ft_puthexa(number, 'X'));

    return (0);
}*/
