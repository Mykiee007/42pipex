/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:01:24 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/11/28 10:42:11 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memcpybwd(unsigned char *d, unsigned const char *s, size_t n)
{
	while (n > 0)
	{
		n--;
		d[n] = s[n];
	}
	return (d);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;

	d = (unsigned char *)dest;
	s = (unsigned const char *)src;
	if (d == s || n == 0)
		return (d);
	if (d < s)
		ft_memcpy(d, s, n);
	else
		ft_memcpybwd(d, s, n);
	return (d);
}
