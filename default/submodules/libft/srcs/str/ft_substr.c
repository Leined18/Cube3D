/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:37:56 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/05 10:04:39 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*str_ptr;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	else if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	s += start;
	str_ptr = str;
	*(str + len) = '\0';
	while (len-- && *s)
		*str++ = *s++;
	return (str_ptr);
}
/*
int	main(void)
{
	const char	*cadena = "Hola, mundoa";
	int			inicio = 1;
	size_t		longitud = 1;
	char		*subcadena;

	subcadena = ft_substr("", inicio, longitud);
	if (subcadena != NULL)
	{
		printf("Subcadena: %s\n", subcadena);
		free(subcadena);
	}
	return (0);
}*/
