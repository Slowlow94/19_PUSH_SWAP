/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:23:38 by salowie           #+#    #+#             */
/*   Updated: 2023/08/30 15:48:17 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/push_swap.h"
#include "INCS/ft_printf.h"

int	ft_error(void)
{
	write (2, "Error\n", 6);
	return (1);
}

int	parse_and_create_linkchain(t_list **head_a, int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc <= 2)
	{
		if (argv[i] && (is_num(argv[i]) == 0))
			return (ft_error());
		if (ft_atoi(argv[i]) < INT_MIN || ft_atoi(argv[i]) > INT_MAX)
			return (ft_error());
		else
			return (1);
	}
	while (argv[i])
	{
		if (!is_num(argv[i]))
			return (ft_error());
		if (ft_atoi(argv[i]) < INT_MIN || ft_atoi(argv[i]) > INT_MAX)
			return (ft_error());
		if (fill_linkchain(head_a, argv, i) == 1)
			return (ft_error());
		i++;
	}
	return (0);
}

int	fill_linkchain(t_list **head_a, char **argv, int i)
{
	int		cnt;
	t_list	*new_node;

	cnt = ft_atoi(argv[i]);
	if (is_dubble(head_a, cnt) == 0)
		return (1);
	if (i == 1)
		*head_a = ft_lc_new(cnt);
	else
	{
		new_node = ft_lc_new(cnt);
		if (new_node == NULL)
		{
			ft_lc_clear(head_a);
			return (1);
		}
		ft_lc_add_back(head_a, new_node);
	}
	return (0);
}
