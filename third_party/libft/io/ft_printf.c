/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 05:48:56 by maldavid          #+#    #+#             */
/*   Updated: 2022/10/12 22:44:03 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <libft.h>

static char	*ft_stoup(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_islower(str[i]))
			str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

static int	ft_fmt_addr(long long addr)
{
	char	hex[17];

	ft_bzero(hex, 17);
	if (addr == 0)
		return (ft_putstr("(nil)"));
	ft_nlltoa(addr, hex, 0, 16);
	return (ft_putstr("0x") + ft_putstr(hex));
}

static char	*ft_fmt_hex(int hex, char array[17])
{
	if (hex < 0)
		return (ft_nlltoa((unsigned int)hex, array, 0, 16));
	return (ft_nlltoa(hex, array, 0, 16));
}

static int	ft_fmt(const char *src, va_list args)
{
	char	hex[17];

	ft_bzero(hex, 17);
	if (*src == '%')
		return (ft_putchar('%'));
	else if (*src == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*src == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*src == 'p')
		return (ft_fmt_addr((long long)va_arg(args, void *)));
	else if (*src == 'i' || *src == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (*src == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if (*src == 'x')
		return (ft_putstr(ft_fmt_hex(va_arg(args, int), hex)));
	else if (*src == 'X')
		return (ft_putstr(ft_stoup(ft_fmt_hex(va_arg(args, int), hex))));
	else
		return (ft_putchar('%') + ft_putchar(va_arg(args, int)));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	va_start(args, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += ft_fmt(str, args);
		}
		else
		{
			ft_putchar(*str);
			len++;
		}
		str++;
	}
	va_end(args);
	return (len);
}
