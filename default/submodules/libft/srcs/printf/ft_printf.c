/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:02:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/26 12:52:19 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char format, int fd)
{
	void	*p;

	if (format == 'd' || format == 'i')
		return (ft_putnbr_fd(va_arg(args, int), fd));
	else if (format == 'c')
		return (ft_putchar_fd(va_arg(args, int), fd));
	else if (format == 's')
		return (ft_putstr_fd(va_arg(args, char *), fd));
	else if (format == 'p')
	{
		p = va_arg(args, void *);
		if (p)
			return (ft_putaddress_fd(p, fd));
		return (ft_putstr_fd("(nil)", fd));
	}
	else if (format == 'u')
		return (ft_putunsigned_fd(va_arg(args, unsigned int), fd));
	else if (format == 'X' || format == 'x')
		return (ft_puthexa_fd(va_arg(args, int), format, fd));
	else if (format == '%')
		return (ft_putchar_fd('%', fd));
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		length;

	if (!str)
		return (-1);
	i = 0;
	length = 0;
	va_start(args, str);
	while (*(str + i))
	{
		if (*(str + i) == '%' && ft_strchr("cspdiuxX%", *(str + i + 1)))
		{
			length += ft_format(args, *(str + i + 1), 1);
			i++;
		}
		else
			length += ft_putchar_fd(*(str + i), 1);
		i++;
	}
	va_end(args);
	return (length);
}
/*
int	main(void)
{
	void	*p;
	char	s[] = "buenas";

	p = s;
	ft_printf("%d", ft_printf("\001\002\007\v\010\f\r\n"));

	ft_printf("\nMI FUNCION\n!!!!!!!!!!SEPARADOR¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡\nORIGINAL\n");

	printf("%d", printf("\001\002\007\v\010\f\r\n"));
	return (0);
}*/
