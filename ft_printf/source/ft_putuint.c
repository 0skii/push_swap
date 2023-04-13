/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:58:37 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/04/13 12:46:34 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putuint(unsigned int nbr)
{
	int	x;

	x = 0;
	if (nbr > 9)
	{
		x += ft_putuint(nbr / 10);
		x += ft_putuint(nbr % 10);
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
