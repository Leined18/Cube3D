/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:15:28 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/26 12:41:24 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase_fd(int nbr, const char *base, int fd)
{
	int		base_len;
	int		len;
	long	nb;
	char	c;

	base_len = ft_strlen(base);
	len = 0;
	if (nbr < 0)
	{
		len = write(fd, "-", 1);
		nb = -((long)nbr);
	}
	else
		nb = (long)nbr;
	if (nb > (base_len - 1))
		return (ft_putbase_fd(nb / base_len, base, fd));
	c = *(base + (nb % base_len));
	return (write(fd, &c, 1) + len);
}
