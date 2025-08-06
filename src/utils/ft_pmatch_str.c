/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pmatch_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:36:01 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/06 10:25:23 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pmatch_str(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	if (ft_strlen(s1) < n || ft_strlen(s2) < n)
		return (0);
	if (ft_strncmp(s1, s2, n) != 0)
		return (0);
	if (s1[n] != '\0')
		return (0);
	return (1);
}
