/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:04:35 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/11/27 10:38:59 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	srclen = 0;
	while (src[srclen] != '\0')
		srclen++;
	dstlen = 0;
	while (dest[dstlen] != '\0')
		dstlen++;
	if (size <= dstlen)
		return (size + srclen);
	i = 0;
	while (dstlen + i < size - 1 && src[i] != '\0')
	{
		dest[dstlen + i] = src[i];
		i++;
	}
	dest[dstlen + i] = '\0';
	return (dstlen + srclen);
}
