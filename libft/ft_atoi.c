/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:39:25 by hguillau          #+#    #+#             */
/*   Updated: 2022/11/14 15:53:27 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int	ft_isspace(int i, char *str)
{
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

int	ft_neg(char *str, int *i)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
		{
			(*i)++;
			return (-1);
		}
		(*i)++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int			i;
	int			neg;
	long int	result;

	i = 0;
	result = 0;
	ft_isspace(i, str);
	neg = ft_neg(str, &i);
	if (!ft_isdigit(str[i]))
		ft_error();
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	if (!ft_isdigit(str[i]) && str[i])
		ft_error();
	result *= neg;
	if (result > 2147483647 || result < -2147483648)
		ft_error();
	return (result);
}
