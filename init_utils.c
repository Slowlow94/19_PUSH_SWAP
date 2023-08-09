/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:50:15 by salowie           #+#    #+#             */
/*   Updated: 2023/08/09 14:04:40 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/push_swap.h"
#include "INCS/ft_printf.h"

int	is_num(char *str) // n'est pas correct
{
	while (*str)
	{
		if ((*str >= '0' && *str <= '9') || *str == '-' || *str == '+')
			str++;
		else
			return (1);
	}
	return (0);
}

int	is_dubble(t_list *head_a, int value)
{
	while (head_a != NULL)
	{
		if (value == *(int *)head_a->c)
		{
			ft_printf("content : %d\n", *head_a->c);
			return (1);
		}
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
