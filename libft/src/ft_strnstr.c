/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:09:44 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/11/27 10:00:13 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *n, size_t size)
{
	size_t	i;
	size_t	j;

	if (n[0] == '\0')
		return ((char *)s);
	i = 0;
	while (s[i] != '\0' && i < size)
	{
		j = 0;
		while (s[i + j] == n[j] && (i + j) < size)
		{
			if (n[j + 1] == '\0')
				return ((char *)&s[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
