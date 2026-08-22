#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define FD 1

int		ft_printf(const char *s, ...);
int		ft_numlen(long n);
int		ft_strlen(char *s);
int		ft_hexlen(long n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(long n);
int		ft_putptr(void *ptr);
int		ft_putnbr_hex(unsigned long n, int isx);

#endif
