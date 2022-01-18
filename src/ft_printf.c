/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:56:57 by mtrembla          #+#    #+#             */
/*   Updated: 2021/11/20 10:06:56 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"
/*
p = argument de pointeur void * est imprimé en hexadécimal
d = imprime nombre décimal (base 10):
i = imprime un entier en base 10
u = imprime nombre décimal non signé (base 10)
x = imprime un nombe en hexadécimal minuscule (base 16)
X = comme x mais en majuscule
*/
int	ft_checkflag(va_list list, char *str)
{
	int		ret;
	char	lock;

	lock = 1;
	ret = 0;
	if (*str == 'c')
		ret += ft_putchar(va_arg(list, int));
	else if (*str == 's')
		ret += ft_putstr(va_arg(list, char *));
	else if (*str == 'x' || *str == 'X' || *str == 'p')
		ret += ft_hexa(va_arg(list, unsigned long), str, lock);
	else if (*str == 'd' || *str == 'i' || *str == 'u')
		ret += ft_decimal(va_arg(list, int), str);
	else if (*str == '%')
		ret += ft_putchar('%');
	return (ret);
}

int	ft_printf(const char *something, ...)
{
	va_list	list;
	int		printy;
	char	*str;

	va_start(list, something);
	printy = 0;
	str = (char *) something;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			printy += ft_checkflag(list, str);
		}
		else
			printy += ft_putchar(*str);
		str++;
	}
	va_end(list);
	return (printy);
}
