/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:17:13 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/04/13 12:46:09 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putlu(unsigned int nbr, unsigned int base, char c)
{
	int	x;

	x = 0;
	if (nbr > (base - 1))
		x = ft_putlu(nbr / base, base, c) + ft_putlu(nbr % base, base, c);
	else if (nbr < 10)
	{
		nbr = nbr + 48;
		x += ft_putchar(nbr);
	}
	else if (c == 'l')
	{
		nbr = nbr + 87;
		x += ft_putchar(nbr);
	}
	else if (c == 'U')
	{
		nbr = nbr + 55;
		x += ft_putchar(nbr);
	}
	return (x);
}
