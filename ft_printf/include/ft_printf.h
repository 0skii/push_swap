/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:35:29 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/01/26 14:53:31 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *c);
int		ft_putuint(unsigned int nbr);
int		ft_putptr(unsigned long n);
int		ft_putnbr_base(long n, int base);
int		ft_putlu(unsigned int nbr, unsigned int base, char c);

#endif
