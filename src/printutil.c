/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printutil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:38:51 by mtrembla          #+#    #+#             */
/*   Updated: 2021/11/20 10:07:18 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

int	ft_putchar(char c)
{
	int	ret;

	ret = write (1, &c, 1);
	return (ret);
}

int	ft_putstr(char *str)
{
	int	ret;

	ret = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
	{
		ret += write (1, str, 1);
		str++;
	}
	return (ret);
}

int	ft_decimal(int nbr, char *str)
{
	unsigned int	n;
	unsigned int	ret;

	ret = 0;
	if (nbr < 0 && *str != 'u')
	{
		ret += ft_putchar ('-');
		nbr *= -1;
	}
	n = (unsigned int) nbr;
	if (n > 9)
		ret += ft_decimal(n / 10, str);
	ret += ft_putchar(n % 10 + '0');
	return (ret);
}

int	ft_hexa(unsigned long n, char *str, char lock)
{
	char		*base;
	int			ret;

	ret = 0;
	if (*str == 'x' || *str == 'X')
		n = (unsigned int) n;
	if (*str == 'p' && lock == 1)
		ret += write (1, "0x", 2);
		lock --;
	base = "0123456789abcdef";
	if (*str == 'X')
		base = "0123456789ABCDEF";
	if (n / 16 != 0)
		ret += ft_hexa(n / 16, str, lock);
	ret += ft_putchar(base[n % 16]);
	return (ret);
}
