/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:28:29 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/12/22 10:55:53 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr(int a);
int		ft_puthexlower(unsigned int a);
int		ft_puthexlowerlong(unsigned long a);
int		ft_puthexupper(unsigned int a);
int		ft_putunsigned(unsigned int a);
int		ft_putptr(void *ptr);
int		ft_printf(const char *s, ...);
char	*ft_strchr(const char *s, int c);

#endif // FT_PRINTF