#include <stdarg.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define FD 1

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

int	ft_strlen(char *s)
{
	const char	*ss = s;

	while (*s)
		s++;
	return (s - ss);
}

int	ft_putchar(char c)
{
	return (write(FD, &c, 1));
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

int	ft_putstr(char *s)
{
	const int	len = ft_strlen(s);
	char		*string;
	int			i;

	if (!s)
		return (write(FD, "(null)", 6));
	string = malloc(len);
	if (!string)
		return (free(string), -1);
	i = 0;
	while (s[i] != 0)
	{
		string[i] = s[i];
		++i;
	}
	if (write(FD, string, len) == -1)
		return (free(string), -1);
	return (free(string), len);
}

int	ft_putnbr(long n)
{
	int		len;
	char	*string;

	len = ft_numlen(n);
	string = malloc(len + 1);
	if (!string)
		return (-1);
	if (n < 0)
	{
		n *= -1;
		string[0] = '-';
	}
	string[len] = 0;
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

/* int	main(void) */
/* { */
/* 	char	*string; */

/* 	int		s; */

/* 	printf("1:%d\n", ft_printf("\t%c\t\t\t", 'c')); */
/* 	printf("1:%d\n", printf("\t%c\t\t\t", 'c')); */
/* 	printf("2:%d\n", ft_printf("\t%d\t\t\t", INT_MIN)); */
/* 	printf("2:%d\n", printf("\t%d\t\t\t", INT_MIN)); */
/* 	printf("3:%d\n", ft_printf("\t%d\t\t\t", INT_MAX)); */
/* 	printf("3:%d\n", printf("\t%d\t\t\t", INT_MAX)); */
/* 	printf("4:%d\n", ft_printf("\t%d\t\t\t", 42)); */
/* 	printf("4:%d\n", printf("\t%d\t\t\t", 42)); */
/* 	printf("5:%d\n", ft_printf("\t%d\t\t\t", -42)); */
/* 	printf("5:%d\n", printf("\t%d\t\t\t", -42)); */
/* 	printf("6:%d\n", ft_printf("\t%i\t\t\t", 0)); */
/* 	printf("6:%d\n", printf("\t%i\t\t\t", 0)); */
/* 	printf("7:%d\n", ft_printf("\t%u\t\t\t", INT_MIN)); */
/* 	printf("7:%d\n", printf("\t%u\t\t\t", INT_MIN)); */
/* 	string = malloc(10); */
/* 	int i = 0; */
/* 	while (i < 9) */
/* 	{ */
/* 		string[i] = 0; */
/* 		i++; */
/* 	} */
/* 	s = 0; */
/* 	printf("8:%d\n", printf("\t%p\t\t\t", (void *)string)); */
/* 	printf("8:%d\n", ft_printf("\t%p\t\t\t", (void *)string)); */
/* 	printf("0:%d\n", ft_printf("\t%X\t\t\t", s)); */
/* 	printf("0:%d\n", ft_printf("\t%%\t\t\t")); */
/* 	printf("0:%d\n", ft_printf("\t%p\t\t\t", NULL)); */
/* 	free(string); */
/* } */
