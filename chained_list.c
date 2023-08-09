/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:46:08 by salowie           #+#    #+#             */
/*   Updated: 2023/08/09 17:03:49 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/push_swap.h"
#include "INCS/ft_printf.h"

t_list	*ft_lstnew(int *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->c = content;
	node->next = NULL;
	return (node);
}

t_list	*ft_lstlast(t_list *lst, int i)
{
	int	j;
	int	size;

	if (!lst)
		return (NULL);
	j = 0;
	size = ft_lstsize(lst) - i;
	while (lst->next != NULL && j < (size - 1))
	{
		lst = lst->next;
		j++;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst, 0)->next = new;
}

int	ft_lstsize(t_list *lst)
{
	int		lenght;

	lenght = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		lenght++;
		lst = lst->next;
	}
	return (lenght);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	temp = NULL;
	if (!lst)
		return ;
	while (*lst != NULL)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp->c);
		free(temp);
	}
	*lst = NULL;
}
