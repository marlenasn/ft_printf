#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	len;
	
	len = 0;
	if (s != NULL)
	{
		while (*s)
		{
			write(1, s, 1);
			len++;
			s++;
		}
	}
	else
	{
		write(1, "(null)", 6);
		len = 6;
	}
	return (len);
}
