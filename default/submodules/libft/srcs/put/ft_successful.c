/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_successful.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:29:08 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/28 18:24:05 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_successful(char *msg, t_bool yeet)
{
	if (msg && *msg)
		ft_putstr_color_fd(GREEN, msg, 1);
	if (yeet)
		exit(EXIT_SUCCESS);
}
