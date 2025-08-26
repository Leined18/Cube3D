/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:37:34 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/05 10:04:39 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	rec_print(unsigned long n, const char *base, int fd)
{
	int	len;

	len = 0;
	if (n > (ft_strlen(base) - 1))
		len += rec_print(n / ft_strlen(base), base, fd);
	len += ft_putchar_fd(*(base + (n % ft_strlen(base))), fd);
	return (len);
}

int	ft_putaddress_fd(void *format, int fd)
{
	unsigned long	n;
	const char		*base;
	int				len;

	n = (unsigned long)format;
	base = "0123456789abcdef";
	len = ft_putstr_fd("0x", fd);
	len += rec_print(n, base, fd);
	return (len);
}
/*
int main(void)
{
    int chars_written;
    
    void* memory_address = malloc(sizeof(int));
    chars_written = ft_putaddress(memory_address);
    free(memory_address);
    
    void* null_pointer = NULL;
    chars_written = ft_putaddress(null_pointer);
    
    return (0);
}*/
