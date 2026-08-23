/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milnicki <milnicki@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 15:15:42 by milnicki          #+#    #+#             */
/*   Updated: 2026/08/23 12:46:28 by milnicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(FD, &c, 1));
}

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
		return (write(FD, "(null)", 6));
	len = 0;
	while (*s)
	{
		write(FD, s, 1);
		s++;
		len++;
	}
	return (len);
}

int	ft_putnbr(long n)
{
	long	ln;
	long	div;
	char	c;
	int		len;

	ln = n;
	len = 0;
	if (n < 0)
	{
		write(FD, "-", 1);
		ln = -ln;
		len++;
	}
	div = 1;
	while (div * 10 <= ln)
		div *= 10;
	while (div > 0)
	{
		c = (ln / div) + 48;
		write(FD, &c, 1);
		ln %= div;
		div /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_hex(unsigned long n, int isx)
{
	int			mod;
	char		*string;
	int			i;
	int			len;

	if (n == 0)
		return (ft_putchar('0'));
	len = ft_hexlen(n);
	string = malloc(len +1);
	if (!string)
		return (-1);
	string[len] = '\0';
	i = len;
	while (n != 0)
	{
		mod = n % 16;
		if (mod > 9 && isx)
			string[--i] = mod + 87;
		else if (mod > 9)
			string[--i] = mod + 55;
		else if (mod <= 9)
			string[--i] = mod + 48;
		n /= 16;
	}
	return (ft_putstr(string), free(string), len);
}

int	ft_putptr(void *ptr)
{
	int	acc;

	acc = 0;
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	if (ft_putstr("0x") == -1)
		return (-1);
	acc = ft_putnbr_hex((unsigned long)ptr, 1);
	if (acc == -1)
		return (-1);
	return (acc + 2);
}
