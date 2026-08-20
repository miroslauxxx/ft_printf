#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#define FD 1

int		ft_numlen(long n)
{
	int			len = 1;
	
	if(n < 0)
	{
		n *= -1;
		len++;
	}
	while(n > 9)
	{
		n /= 10;
		len++;
	}
	return(len);
}

int		ft_strlen(char *s)
{
	const char 	*ss = s;

	while(*s)
		s++;
	return(s - ss);
}

int ft_putchar(char c)
{
	return(write(FD, &c, 1));
}

int		ft_hexlen(long n)
{
	long power;
	int i;

	power = 16;
	i = 1;
	if(n < 0)
	{
		n = -n;
		i++;
	}

	while(power - n < 0)
	{
		power *= 16;
		i++;
	}
	return(i);
}

int		ft_putstr(char *s)
{
	const int 	len = ft_strlen(s); 
	char 		*string;
	int			i;

	if(!s)
		return(write(FD, "(null)", 6));
	string = malloc(len);
	if(!string)
		return(free(string), -1);
	i = 0;
	while(s[i] != 0)
	{
		string[i] = s[i];
		++i;
	}
	if (write(FD, string, len) == -1)
		return(free(string), -1);
	return(free(string), len);
}

int		ft_putnbr(long n)
{
	int			len;
	char		*string;

	len = ft_numlen(n);
	string = malloc(len +1);
	if (!string)
		return(-1);
	if(n == -2147483648)
		return(free(string), ft_putstr("-2147483648"));
	if(n < 0)
	{
		n *= -1;
		len++;
		string[0] = '-';
	}
	string[len] = 0;
	len -= 1;
	while(n > 9)
	{
		string[len--] = n % 10 + 48;
		n /= 10;
	}
	string[len] = n + 48;
	ft_putstr(string);
	len = ft_strlen(string);
	return(free(string), ft_numlen(n));
}

int		ft_putnbr_hex(long n, int isx)
{
	int 		mod;
	char 		*string;
	int			len = ft_hexlen(n); 

	string = malloc(len + 1);
	if (!string)
		return(-1);
	if(n < 0)
	{
		string[0] = '-';
		n = -n;
	}
	string[len] = 0;
	len -= 1;
	while(n != 0)
	{
		mod = n % 16;
		if(mod % 16 > 9 && isx)
			string[len--] = mod + 87;
		else if(mod % 16 > 9)
			string[len--] = mod + 55; 
		else if(mod % 16 < 9)
			string[len--] = mod + 48;
		n /= 16;
	}
	ft_putstr(string);
	free(string);
	return(0);
}

static int ft_conversion(const char type, va_list ap)
{
	if(type == 'c')
		return(ft_putchar(va_arg(ap, int)));
	else if(type == 'd' || type == 'i')
		return(ft_putnbr(va_arg(ap, int)));
	else if(type == 'x')
		return(ft_putnbr_hex(va_arg(ap, long), 0));
	else if(type == 'X')
		return(ft_putnbr_hex(va_arg(ap, long), 1));
	return(-1);
}

int	ft_printf(char const *s, ...)
{
	int i = 0;
	int len;
	int check;
	
	va_list  ap;
	len = 0;
	va_start(ap, s);
	while(s[i] != '\0')
	{
		if(s[i] == '%')
		{
			check = ft_conversion(s[++i], ap);
			if(check == -1)
				return(-1);
			len += check;
		}
		else
		{
			if(write(FD, &s[i], 1) == -1)
				return(-1);
			len++;
		}
		i++;
	}
	va_end(ap);
	return(1);
}

int	main(void)
{
	ft_printf("\t%x\t", 41099);
}
