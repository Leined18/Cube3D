/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:06:26 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/26 12:51:22 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "shared.h"

int	ft_format(va_list args, const char format, int fd);
int	ft_printf_fd(int fd, const char *format, ...);
int	ft_printf(const char *format, ...);

#endif
