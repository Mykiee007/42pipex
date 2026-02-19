/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:38:43 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/11/27 16:16:28 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigits(long n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static void	ft_topositive(char *s, long int *nb)
{
	s[0] = '-';
	*nb = -(*nb);
}

char	*ft_itoa(int n)
{
	long int	nb;
	int			len;
	char		*s;

	nb = (long int)n;
	len = ft_countdigits(nb);
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (nb == 0)
	{
		s[0] = '0';
		return (s);
	}
	if (nb < 0)
		ft_topositive(s, &nb);
	while (nb > 0)
	{
		s[--len] = nb % 10 + '0';
		nb /= 10;
	}
	return (s);
}
