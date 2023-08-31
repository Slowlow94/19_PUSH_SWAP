/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:23:08 by salowie           #+#    #+#             */
/*   Updated: 2023/08/31 14:01:10 by salowie          ###   ########.fr       */
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
	if (argc <= 1)
		return (1);
	if (parse_and_create_linkchain(&head_a, argc, argv) == 1)
		return (1);
	wich_sort(&head_a, &head_b);
	ft_lc_clear(&head_a);
	return (0);
}
