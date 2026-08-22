/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milnicki <milnicki@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 15:15:42 by milnicki          #+#    #+#             */
/*   Updated: 2026/08/22 19:14:54 by green            ###   ########.fr       */
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
		if (write(FD, "-", 1) == -1)
			return(-1);
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
	const int	init_len = ft_hexlen(n);
	int			len;

	if (n == 0)
		return (putchar('0'));
	len = ft_hexlen(n);
	string = malloc(len);
	if (!string)
		return (-1);
	len -= 1;
	while (n != 0)
	{
		mod = n % 16;
		if (mod > 9 && isx)
			string[len--] = mod + 87;
		else if (mod > 9)
			string[len--] = mod + 55;
		else if (mod <= 9)
			string[len--] = mod + 48;
		n /= 16;
	}
	ft_putstr(string);
	return (free(string), init_len);
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
