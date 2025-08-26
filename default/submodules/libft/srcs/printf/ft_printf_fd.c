/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:53:07 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/26 12:52:01 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_fd(int fd, const char *str, ...)
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
			length += ft_format(args, *(str + i + 1), fd);
			i++;
		}
		else
			length += ft_putchar_fd(*(str + i), fd);
		i++;
	}
	va_end(args);
	return (length);
}
