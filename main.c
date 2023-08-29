/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:23:08 by salowie           #+#    #+#             */
/*   Updated: 2023/08/29 13:54:50 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/push_swap.h"
#include "INCS/ft_printf.h"

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;

	head_b = NULL;
	head_a = NULL;
	if (parse_and_create_linkchain(&head_a, argc, argv) == 1)
		return (1);
	wich_sort(&head_a, &head_b);
	// ft_printf("Stack A\n\n\n");
	// ft_print_stack_a(&head_a);
	// ft_printf("-----------------------\n");
	// ft_printf("Stack B\n\n\n");
	// ft_print_stack_a(&head_b);
	ft_lc_clear(&head_a);
	ft_lc_clear(&head_b);
	// system("leaks push_swap");
	return (0);
}
