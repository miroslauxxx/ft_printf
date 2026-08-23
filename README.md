_This project has been created as part of the 42 curriculum by <milnicki>_

### Description

This project is part of Rank 1 core curriculum 42 Berlin. It's goal is reimplementing `printf` function from `stdio`, it's prototype:

int ft\_printf(const char *, ...); #Produce output according to a format, write to FD and return amount of printed characters.

 Function has to handle the following conversions: cspdiuxX%, where:
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign. 

Some requirements:
• Do not implement the buffer management of the original printf().
• Using `ar` to create library is required. Using the libtool command is forbidden.
• Your libftprintf.a has to be created at the root of your repository.

### Instructions

$ git clone https://github.com/miroslauxxx/ft_printf.git

# Change LIBFT\_DIR to actual location

$ make norm # run `make fclean` and `norminette`

$ make tester # clone tester repository

$ make # default rule to compile libftprintf.a

# include "ft\_printf.h" into your cobebase and call ft\_printf, when linking - do not forget to append libftprintf.a into your sources !

### Resources 

geeksforgeeks
man pages
tldr
git repositories

### Detailed explanation

int	ft\_hexlen(unsigned long n); # determine amount of base 16 cells for string beeing allocated on heap inside ft\_putnbr_hex()
int	ft\_putchar(char c); # write char to FD and return 1 on success
int	ft\_putstr(char \*s); # write string to FD and return length of string on success, otherwise -1
int	ft\_putnbr(long n); # write number to FD and return length of string on success, otherwise -1
int	ft\_putnbr\_hex(unsigned long n, int isx); # dynamically allocate memory for base16 number, print string to FD and return length of string, otherwise -1 
int	ft\_putptr(void \*ptr); # write pointer address with prefix 0x to FD and return it's length



