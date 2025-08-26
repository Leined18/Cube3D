/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:39:12 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/26 12:59:19 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(void *content)
{
	if (content)
		return (ft_printf("Content: %p\n", content));
	else
		return (ft_printf("Content: NULL\n"));
	return (0);
}

int	main(void)
{
	char	*str;

	str = "Hello, World!";
	ft_printf_fd(0, "hola %d, %s", check(str), "hola");
	return (0);
}
