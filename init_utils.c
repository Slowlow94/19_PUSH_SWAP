/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:50:15 by salowie           #+#    #+#             */
/*   Updated: 2023/08/17 17:35:45 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/push_swap.h"
#include "INCS/ft_printf.h"

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

int	is_dubble(t_list *head_a, int value)
{
	while (head_a != NULL)
	{
		if (value == head_a->c)
			return (1);
		head_a = head_a->next;
	}
	return (0);
}

long	ft_atoi(const char *str)
{
	long long	res;
	int			sign;
	char		*s;

	s = (char *)str;
	res = 0;
	sign = 1;
	// while ((*s > 8 && *s < 14) || *s == 32)
	// 	s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + *s - 48;
		s++;
	}
	return (sign * res);
}
