/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:24:45 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/11/28 16:13:30 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdlib.h>
//#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, end - start));
}

/*int main(void)
{
char *s;

	s = ft_strtrim("   xxx   xxx", " x");
	printf("'%s'\n", s);
	free(s);

	s = ft_strtrim("", "abcd");
	printf("'%s'\n", s);
	free(s);

	s = ft_strtrim("   ", " ");
	printf("'%s'\n", s);
	free(s);

	s = ft_strtrim("abc", "");
	printf("'%s'\n", s);
	free(s);

	s = ft_strtrim("   abc   ", " ");
	printf("'%s'\n", s);
	free(s);

	return (0);
}*/