/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_un_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiecek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:28:22 by mwiecek           #+#    #+#             */
/*   Updated: 2024/03/24 21:52:46 by mwiecek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_put_un_nbr_fd(unsigned int n, int fd)
{
        char    a;

        if (n >= 16)
        {
                ft_put_un_nbr_fd(n / 16, fd);
                ft_put_un_nbr_fd(n % 16, fd);
        }
        else
        {
		if (n < 10) 
                	a = n + '0';
		else 
			a = n + 55;
		write (fd, &a, 1);
        }
}

int	main(void)
{
	ft_put_un_nbr_fd(-650000, 1);
	return (0);
}
