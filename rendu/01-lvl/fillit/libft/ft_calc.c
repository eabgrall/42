/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:27:22 by alngo             #+#    #+#             */
/*   Updated: 2016/12/02 18:31:36 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_calc(int a, int b, char c)
{
	if (c == '+')
		return (ft_mathadd(a, b));
	if (c == '-')
		return (ft_mathsub(a, b));
	if (c == '*')
		return (ft_mathmul(a, b));
	if (c == '/')
		return (ft_mathdiv(a, b));
	if (c == '%')
		return (ft_mathmod(a, b));
	return (0);
}
