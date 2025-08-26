/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:28:41 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/18 10:34:23 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief check if the string is numeric
 * @param str string to be checked if is numeric
 */
int	ft_isstrnum(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = FALSE;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			n = 1;
		else
			n = 0;
		i++;
	}
	return (n);
}
