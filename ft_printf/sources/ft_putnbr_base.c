/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:18:25 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/04/13 12:46:16 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr_base(long n, int base)
{
	int	x;

	x = 0;
	if (n < 0)
	{
		x += ft_putchar('-') + ft_putnbr_base(-n, base);
	}
	else if (n > (base - 1))
	{
		x += ft_putnbr_base(n / base, base) + ft_putnbr_base(n % base, base);
	}
	else if (n < 10)
	{
		n = n + 48;
		x += ft_putchar(n);
	}
	else
	{
		n = n + 55;
		x += ft_putchar(n);
	}
	return (x);
}
