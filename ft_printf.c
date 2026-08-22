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

int	main(void)
{
	char	*string;

	int		s;

	printf("1:%d\n", ft_printf("\t%c\t\t\t", 'c'));
	printf("1:%d\n", printf("\t%c\t\t\t", 'c'));
	printf("2:%d\n", ft_printf("\t%d\t\t\t", INT_MIN));
	printf("2:%d\n", printf("\t%d\t\t\t", INT_MIN));
	printf("3:%d\n", ft_printf("\t%d\t\t\t", INT_MAX));
	printf("3:%d\n", printf("\t%d\t\t\t", INT_MAX));
	printf("4:%d\n", ft_printf("\t%d\t\t\t", 42));
	printf("4:%d\n", printf("\t%d\t\t\t", 42));
	printf("5:%d\n", ft_printf("\t%d\t\t\t", -42));
	printf("5:%d\n", printf("\t%d\t\t\t", -42));
	printf("6:%d\n", ft_printf("\t%i\t\t\t", 0));
	printf("6:%d\n", printf("\t%i\t\t\t", 0));
	printf("7:%d\n", ft_printf("\t%u\t\t\t", INT_MIN));
	printf("7:%d\n", printf("\t%u\t\t\t", INT_MIN));
	string = malloc(10);
	int i = 0;
	while (i < 9)
	{
		string[i] = 0;
		i++;
	}
	s = 0;
	printf("8:%d\n", printf("\t%p\t\t\t", (void *)string));
	printf("8:%d\n", ft_printf("\t%p\t\t\t", (void *)string));
	printf("0:%d\n", ft_printf("\t%X\t\t\t", s));
	printf("0:%d\n", ft_printf("\t%%\t\t\t"));
	printf("0:%d\n", ft_printf("\t%p\t\t\t", NULL));
	free(string);
}
