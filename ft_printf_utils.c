/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milnicki <milnicki@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 15:15:52 by milnicki          #+#    #+#             */
/*   Updated: 2026/08/22 21:00:48 by green            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_hexlen(unsigned long n)
{
	int		len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}
