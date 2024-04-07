/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiecek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:41:55 by mwiecek           #+#    #+#             */
/*   Updated: 2024/03/25 19:00:16 by mwiecek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <unistd.h>

void    ft_print_ptr(unsigned long n, int fd)
{
        char    a;

        if (n >= 16)
        {
                ft_print_ptr(n / 16, fd);
                ft_print_ptr(n % 16, fd);
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
	void	*ptr;
//	printf("%-0+5d", -42);
//	printf("%d", -+472);
//	printf("%d", +-42);
//	printf(-42);
//	printf("kjsdfkjfds");
//	printf("%d", -42);
        printf("%d\n%p\n%x\n", 1234, ptr, 9840938);
	return (0);
}
