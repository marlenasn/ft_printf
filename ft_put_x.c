#include "ft_printf.h"

int	ft_put_x(unsigned int n)
{
	char	a;
	int	len;
	
	len = 1;
	if (n >= 16)
	{
		len = len + ft_put_x(n / 16);
		ft_put_x(n % 16);
	}
	else
	{
		if (n < 10)
			a = n + '0';
		else
			a = (n - 10) + 'a';
		write (1, &a, 1);
	}
	return (len);
}

