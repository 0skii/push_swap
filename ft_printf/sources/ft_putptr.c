/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 01:42:07 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/04/13 12:46:21 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_ptr(unsigned long nbr)
{
	int	x;

	x = 0;
	if (nbr > 15)
	{
		x += ft_ptr(nbr / 16);
		x += ft_ptr(nbr % 16);
	}
	else if (nbr < 10)
	{
		nbr = nbr + 48;
		x += ft_putchar(nbr);
	}
	else
	{
		nbr = nbr + 87;
		x += ft_putchar(nbr);
	}
	return (x);
}

int	ft_putptr(unsigned long n)
{
	if (n == 0)
		return (write(1, "(nil)", 5));
	return (ft_putstr("0x") + ft_ptr(n));
}
