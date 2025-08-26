/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:27:04 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/26 11:58:16 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(char *err, t_bool yeet)
{
	if (err && *err)
		ft_putstr_color_fd(RED, err, 2);
	if (yeet)
		exit(EXIT_FAILURE);
}
