/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:54:22 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/12/22 10:53:37 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include "libft.h"

int	ft_puthexlower(unsigned int a)
{
	int		count;
	char	*hex;

	hex = "0123456789abcdef";
	count = 0;
	if (a >= 16)
		count += ft_puthexlower(a / 16);
	count += ft_putchar (hex[a % 16]);
	return (count);
}

int	ft_puthexupper(unsigned int a)
{
	int		count;
	char	*hex;

	hex = "0123456789ABCDEF";
	count = 0;
	if (a < 0)
		a = -a;
	else if (a >= 16)
		count += ft_puthexupper(a / 16);
	count += ft_putchar (hex[a % 16]);
	return (count);
}

int	ft_puthexlowerlong(unsigned long a)
{
	int		count;
	char	*hex;

	hex = "0123456789abcdef";
	count = 0;
	if (a >= 16)
		count += ft_puthexlowerlong(a / 16);
	count += ft_putchar (hex[a % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int				count;
	unsigned long	n;

	count = 0;
	n = (unsigned long) ptr;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count += ft_putstr("0x");
	count += ft_puthexlowerlong(n);
	return (count);
}
