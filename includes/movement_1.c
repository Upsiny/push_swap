/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 09:30:29 by hguillau          #+#    #+#             */
/*   Updated: 2022/11/11 20:03:44 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list **lst)
{
	int	data;

	data = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = data;
	ft_printf("sa\n");
}

void	ft_swap_b(t_list **lst)
{
	int	data;

	data = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = data;
	ft_printf("sb\n");
}

void	ft_swap_swap(t_list **lst_a, t_list **lst_b)
{
	ft_swap_a(lst_a);
	ft_swap_b(lst_b);
	ft_printf("ss\n");
}

void	ft_push_a(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

	tmp = (*lst_b);
	(*lst_b) = (*lst_b)->next;
	tmp->next = (*lst_a);
	(*lst_a) = tmp;
	ft_printf("pa\n");
}

void	ft_push_b(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

	tmp = (*lst_a);
	(*lst_a) = (*lst_a)->next;
	tmp->next = (*lst_b);
	(*lst_b) = tmp;
	ft_printf("pb\n");
}
