/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 21:47:20 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/14 19:52:48 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_duplicates(t_tab *tab)
{
	int		i;
	int		j;

	i = 0;
	while (i < tab->size)
	{
		j = i + 1;
		while (j < tab->size)
		{
			if (tab->v[i] == tab->v[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_sorted(t_tab *tab)
{
	int	i;

	i = 0;
	while (i + 1 < tab->size)
	{
		if (tab->v[i] > tab->v[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int			check_int(const char *str)
{
	long	sign;
	long	result;
	size_t	i;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] != '\0' && ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		result = result * 10 + (str[i] - '0');
		if ((result > 2147483647 && sign == 1)
			|| (result > 2147483648 && sign == -1))
			return (0);
		i++;
	}
	return (sign * result);
}
