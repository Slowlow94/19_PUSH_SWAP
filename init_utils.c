/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:50:15 by salowie           #+#    #+#             */
/*   Updated: 2023/08/30 14:37:40 by salowie          ###   ########.fr       */
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
		if (str[i] && (str[i] == '+' || str[i] == '-'))
			i++;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] && (str[i] < '0' || str[i] > '9'))
			return (0);
	}
	return (1);
}

int	is_dubble(t_list **head_a, int value)
{
	t_list	*first;

	first = NULL;
	first = *head_a;
	while (first != NULL)
	{
		if (value == first->c)
			return (0);
		first = first->next;
	}
	return (1);
}

long	ft_atoi(const char *str)
{
	long long	res;
	int			sign;
	char		*s;

	s = (char *)str;
	res = 0;
	sign = 1;
	while ((*s > 8 && *s < 14) || *s == 32)
		s++;
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
