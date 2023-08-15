/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:23:38 by salowie           #+#    #+#             */
/*   Updated: 2023/08/15 18:50:50 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/push_swap.h"
#include "INCS/ft_printf.h"

int	ft_error(void)
{
	ft_printf("Error\n");
	return (0);
}

int	parse_and_create_linkchain(t_list **head_a, int argc, char **argv)
{
	int	i;

	if (argc <= 2) // pas d'arg ou 1 seul, pas besoin de trier
	{
		if (argv[1] && is_num(argv[1]) == 1) // que ce n'est pas un entier
			return (ft_error());
		return (0);
	}
	i = 1;
	while (argv[i])
	{
		if (is_num(argv[i]) == 1)
			return (ft_error());
		else
		{
			if (ft_atoi(argv[i]) < INT_MIN || ft_atoi(argv[i]) > INT_MAX)
				return (ft_error());
			fill_linkchain(head_a, argv, i);
			i++;
		}
	}
	return (0);
}

int	fill_linkchain(t_list **head_a, char **argv, int i)
{
	int cnt;
	t_list *new_node;

	cnt = ft_atoi(argv[i]);
	if (is_dubble(*head_a, cnt) == 1)
		return (ft_error());
	if (i == 1)
		*head_a = ft_lstnew(cnt);
	else
	{
		new_node = ft_lstnew(cnt);	
		ft_lstadd_back(head_a, new_node);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list *head_a = NULL;
	t_list *head_b = NULL;
	parse_and_create_linkchain(&head_a, argc, argv);
	wich_sort(&head_a, &head_b);
	ft_printf("Stack A\n\n\n");
	ft_print_stack_a(&head_a);
	ft_printf("-----------------------\n");
	ft_printf("Stack B\n\n\n");
	ft_print_stack_a(&head_b);

	ft_lstclear(&head_a);
	ft_lstclear(&head_b);
	// system("leaks push_swap");
}
