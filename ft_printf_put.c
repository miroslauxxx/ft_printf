#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(FD, &c, 1));
}

int	ft_putstr(char *s)
{
	const int	len = ft_strlen(s);
	char		*string;
	int			i;

	if (!s)
		return (write(FD, "(null)", 6));
	string = malloc(len +1);
	if (!string)
		return (free(string), -1);
	i = 0;
	while (s[i] != 0)
	{
		string[i] = s[i];
		++i;
	}
	string[len] = '\0';
	if (write(FD, string, len) == -1)
		return (free(string), -1);
	return (free(string), len);
}

int	ft_putnbr(long n)
{
	int			len;
	char		*string;

	len = ft_numlen(n);
	string = malloc(len);
	if (!string)
		return (-1);
	if (n < 0)
	{
		n *= -1;
		string[0] = '-';
	}
	/* string[len +1] = '\0'; */
	string[len] = '\0';
	len -= 1;
	while (n > 9)
	{
		string[len--] = n % 10 + 48;
		n /= 10;
	}
	string[len] = n + 48;
	len = ft_strlen(string);
	ft_putstr(string);
	return (free(string), len);
}

int	ft_putnbr_hex(unsigned long n, int isx)
{
	int			mod;
	char		*string;
	const int	init_len = ft_hexlen(n);
	int			len;

	len = ft_hexlen(n);
	string = malloc(len);
	if (!string)
		return (-1);
	len -= 1;
	if (n == 0)
		return (putchar('0'));
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
	int			acc;

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
