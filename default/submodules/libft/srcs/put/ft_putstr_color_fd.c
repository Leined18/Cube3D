/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:12:58 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/26 12:11:24 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_color_fd(char *color, char *s, int fd)
{
	int	len;

	len = ft_putstr_fd(color, fd);
	len += ft_putstr_fd(s, fd);
	len += ft_putstr_fd("\033[0m", fd);
	return (len);
}
