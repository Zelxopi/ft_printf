/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:14:06 by mtrembla          #+#    #+#             */
/*   Updated: 2021/11/16 09:04:59 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_hexa(unsigned long n, char *str, char lock);
int		ft_decimal(int nbr, char *str);
int		ft_checkflag(va_list list, char *str);
int		ft_printf(const char *something, ...);

#endif
