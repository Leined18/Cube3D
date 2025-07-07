/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pmatch_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:36:01 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/30 17:22:53 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// compare two strings and return 1 if both are exactly the same.
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
