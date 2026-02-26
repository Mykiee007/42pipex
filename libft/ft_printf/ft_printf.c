/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:14:33 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/02/26 14:37:16 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>

static void	ft_specifer(va_list *args, char const *s, int *i, int *count)
{
	if (s[*i + 1] == 'c')
		*count += ft_putchar(va_arg(*args, int));
	else if (s[*i + 1] == 's')
		*count += ft_putstr(va_arg(*args, char *));
	else if (s[*i + 1] == 'p')
		*count += ft_putptr(va_arg(*args, void *));
	else if ((s[*i + 1] == 'd' || s[*i + 1] == 'i'))
		*count += ft_putnbr(va_arg(*args, int));
	else if (s[*i + 1] == 'u')
		*count += ft_putunsigned(va_arg(*args, unsigned int));
	else if (s[*i + 1] == 'x')
		*count += ft_puthexlower(va_arg(*args, unsigned int));
	else if (s[*i + 1] == 'X')
		*count += ft_puthexupper(va_arg(*args, unsigned int));
	else if (s[*i + 1] == '%')
		*count += ft_putchar('%');
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			i;
	int			count;

	va_start(args, s);
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && ft_strchr("cspiduxX%", s[i + 1]))
		{
			ft_specifer(&args, s, &i, &count);
			i += 2;
		}
		else
		{
			ft_putchar(s[i]);
			i++;
			count++;
		}
	}
	va_end(args);
	return (count);
}

/*		TEST		*/

//#include <stdio.h>
//#include <limits.h>
//
//int main(void)
//{
//    int     or_ret;
//    int     ft_ret;
//    int     x = 42;
//    int     *ptr = &x;
//    char    *str = "Hello, world!";
//    char    *empty = "";
//    char    *null_str = NULL;
//    unsigned int u_max = UINT_MAX;
//
//    /* %c */
//    printf("===== %%c tests =====\n");
//    or_ret = printf("or: [%c]\n", 'A');
//    ft_ret = ft_printf("ft: [%c]\n", 'A');
//    printf("ret or: %d | ft: %d\n\n", or_ret, ft_ret);
//
//    or_ret = printf("or: [%c]\n", 0);
//    ft_ret = ft_printf("ft: [%c]\n", 0);
//    printf("ret or: %d | ft: %d\n\n", or_ret, ft_ret);
//
//    /* %s */
//    printf("===== %%s tests =====\n");
//    or_ret = printf("or: [%s]\n", str);
//    ft_ret = ft_printf("ft: [%s]\n", str);
//    printf("ret or: %d | ft: %d\n\n", or_ret, ft_ret);
//
//    or_ret = printf("or: [%s]\n", empty);
//    ft_ret = ft_printf("ft: [%s]\n", empty);
//    printf("ret or: %d | ft: %d\n\n", or_ret, ft_ret);
//
//    or_ret = printf("or: [%s]\n", null_str);
//    ft_ret = ft_printf("ft: [%s]\n", null_str);
//    printf("ret or: %d | ft: %d\n\n", or_ret, ft_ret);
//
//    /* %p */
//    printf("===== %%p tests =====\n");
//    or_ret = printf("or: [%p]\n", (void *)ptr);
//    ft_ret = ft_printf("ft: [%p]\n", (void *)ptr);
//    printf("ret or: %d | ft: %d\n\n", or_ret, ft_ret);
//
//    or_ret = printf("or: [%p]\n", (void *)0);
//    ft_ret = ft_printf("ft: [%p]\n", (void *)0);
//    printf("ret or: %d | ft: %d\n\n", or_ret, ft_ret);
//
//    /* %d / %i */
//    printf("===== %%d / %%i tests =====\n");
//    or_ret = printf("or: [%d]\n", 0);
//    ft_ret = ft_printf("ft: [%d]\n", 0);
//    printf("ret or: %d | ft: %d\n\n", or_ret, ft_ret);
//
//    or_ret = printf("or: [%d]\n", 12345);
//    ft_ret = ft_printf("ft: [%d]\n", 12345);
//    printf("ret or: %d | ft: %d\n\n", or_ret, ft_ret);
//
//    or_ret = printf("or: [%i]\n", -12345);
//    ft_ret = ft_printf("ft: [%i]\n", -12345);
//    printf("ret or: %d | ft: %d\n\n", or_ret, ft_ret);
//
//    or_ret = printf("or: [%d]\n", INT_MAX);
//    ft_ret = ft_printf("ft: [%d]\n", INT_MAX);
//    printf("ret or: %d | ft: %d\n\n", or_ret, ft_ret);
//
//    or_ret = printf("or: [%d]\n", INT_MIN);
//    ft_ret = ft_printf("ft: [%d]\n", INT_MIN);
//    printf("ret or: %d | ft: %d\n\n", or_ret, ft_ret);
//
//    /* %u */
//    printf("===== %%u tests =====\n");
//    or_ret = printf("or: [%u]\n", 0u);
//    ft_ret = ft_printf("ft: [%u]\n", 0u);
//    printf("ret or: %d | ft: %d\n\n", or_ret, ft_ret);
//
//    or_ret = printf("or: [%u]\n", 123456789u);
//    ft_ret = ft_printf("ft: [%u]\n", 123456789u);
//    printf("ret or: %d | ft: %d\n\n", or_ret, ft_ret);
//
//    or_ret = printf("or: [%u]\n", u_max);
//    ft_ret = ft_printf("ft: [%u]\n", u_max);
//    printf("ret or: %d | ft: %d\n\n", or_ret, ft_ret);
//
//    /* %x / %X */
//    printf("===== %%x / %%X tests =====\n");
//    or_ret = printf("or: [%x]\n", 0);
//    ft_ret = ft_printf("ft: [%x]\n", 0);
//    printf("ret or: %d | ft: %d\n\n", or_ret, ft_ret);
//
//    or_ret = printf("or: [%x]\n", 305441741);
//    ft_ret = ft_printf("ft: [%x]\n", 305441741);
//    printf("ret or: %d | ft: %d\n\n", or_ret, ft_ret);
//
//    or_ret = printf("or: [%X]\n", 305441741);
//    ft_ret = ft_printf("ft: [%X]\n", 305441741);
//    printf("ret or: %d | ft: %d\n\n", or_ret, ft_ret);
//
//    /* %% */
//    printf("===== %%%% tests =====\n");
//    or_ret = printf("or: [%%]\n");
//    ft_ret = ft_printf("ft: [%%]\n");
//    printf("ret or: %d | ft: %d\n\n", or_ret, ft_ret);
//
//    /* Mixed format */
//    printf("===== Mixed tests =====\n");
//    or_ret = printf("or: char=%c str=%s ptr=%p d=%d u=%u x=%x X=%X %%\n",
//                    'A', str, (void *)ptr, -123, 123u, 48879u, 48879u);
//    ft_ret = ft_printf("ft: char=%c str=%s ptr=%p d=%d u=%u x=%x X=%X %%\n",
//                    'A', str, (void *)ptr, -123, 123u, 48879u, 48879u);
//    printf("ret or: %d | ft: %d\n\n", or_ret, ft_ret);
//
//    return (0);
//}