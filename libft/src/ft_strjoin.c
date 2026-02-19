/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:18:21 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/11/27 16:17:25 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cpystr(char *dest, const char *src, int k)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[k] = src[i];
		i++;
		k++;
	}
	return (k);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		k;
	int		str_len;
	char	*d;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	d = (char *)malloc(str_len * sizeof(char));
	if (d == NULL)
		return (NULL);
	k = 0;
	k = ft_cpystr(d, s1, k);
	k = ft_cpystr(d, s2, k);
	d[k] = '\0';
	return (d);
}

/*int	main(void)
{
	char arr1[] = "Hello";
	char arr2[] = "World";
	char *str;
	str = ft_strjoin(arr1,arr2);
	printf("%s\n", str);
	return (0);
}*/
