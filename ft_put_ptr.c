/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiecek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:59:48 by mwiecek           #+#    #+#             */
/*   Updated: 2024/03/26 13:18:55 by mwiecek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

/*void    ft_print_ptr(unsigned long ptr)
{
        char            a;
        unsigned long   n;

	n = (unsigned long)ptr;

	write(1, "0x", 2);
        if (n >= 16)
        {
                ft_print_ptr(n / 16);
                ft_print_ptr(n % 16);
        }
        else
        {
                if (n < 10)
                        a = n + '0';
                else
                        a = n + 55;
                write (1, &a, 1);
        }
}
*/
void ft_print_ptr(unsigned long ptr) {
    char a;
    unsigned long n;

    write(1, "0x", 2); // Drukuj "0x" tylko na początku

    n = (unsigned long)ptr;

    if (n == 0) {
        write(1, "0", 1); // Drukuj 0, jeśli adres wynosi 0
    } else {
        while (n > 0) {
            if (n % 16 < 10)
                a = (n % 16) + '0';
            else
                a = (n % 16) + 55;
            write(1, &a, 1);
            n /= 16;
        }
    }
}

int	main(void)
{
	void	*ptr;
	
	printf("%p\n", ptr);
	ft_print_ptr(ptr);
	return (0);
}
