/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: green </var/spool/mail/green>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:06:26 by green             #+#    #+#             */
/*   Updated: 2026/08/22 19:07:48 by green            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#define FD 1

static int	ft_conversion(const char type, va_list ap)
{
	if (type == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (type == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (type == 'u')
		return (ft_putnbr(va_arg(ap, unsigned int)));
	else if (type == 'x')
		return (ft_putnbr_hex(va_arg(ap, int), 1));
	else if (type == 'X')
		return (ft_putnbr_hex(va_arg(ap, unsigned long), 0));
	else if (type == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *s, ...)
{
	int		len;
	int		check;
	va_list	ap;

	len = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
		{
			check = ft_conversion(*++s, ap);
			if (check == -1)
				return (-1);
			len += check;
		}
		else
		{
			if (write(FD, s, 1) == -1)
				return (-1);
			len++;
		}
		s++;
	}
	return (va_end(ap), len);
}
