/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:59:33 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/04/13 15:15:04 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_flag(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(*args, unsigned long)));
	else if (c == 'u')
		return (ft_putuint(va_arg(*args, unsigned int)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_base(va_arg(*args, int), 10));
	else if (c == 'x')
		return (ft_putlu(va_arg(*args, unsigned int), 16, 'l'));
	else if (c == 'X')
		return (ft_putlu(va_arg(*args, unsigned int), 16, 'U'));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		n_args;

	va_start(args, str);
	n_args = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			n_args += ft_flag(str[i + 1], &args);
			i++;
		}
		else
			n_args += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (n_args);
}
