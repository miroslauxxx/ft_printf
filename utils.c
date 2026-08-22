#include "ft_printf.h"

int	ft_numlen(long n)
{
	int			len;

	len = 1;
	if (n < 0)
	{
		n *= -1;
		++len;
	}
	while (n > 9)
	{
		n /= 10;
		++len;
	}
	return (len);
}

int	ft_strlen(char *s)
{
	const char	*ss = s;

	while (*s)
		++s;
	return (s - ss);
}

int	ft_hexlen(long n)
{
	long		power;
	int			i;

	power = 16;
	i = 1;
	if (n < 0)
	{
		n = -n;
		++i;
	}
	while (power - n < 0)
	{
		power *= 16;
		++i;
	}
	return (i);
}
