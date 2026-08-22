/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milnicki <milnicki@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 15:15:52 by milnicki          #+#    #+#             */
/*   Updated: 2026/08/22 15:15:55 by milnicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_numlen(long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_hexlen(long n)
{
	long	power;
	int		i;

	power = 16;
	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (power - n < 0)
	{
		power *= 16;
		i++;
	}
	return (i);
}
