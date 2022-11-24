/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:05:52 by hguillau          #+#    #+#             */
/*   Updated: 2022/11/12 13:10:20 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_list **lst, int i)
{
	t_list	*tmp;

	tmp = *lst;
	(*lst) = (*lst)->next;
	tmp->next = NULL;
	ft_lstadd_back(lst, tmp);
	if (i == 1)
		ft_printf("ra\n");
}

void	ft_rotate_b(t_list **lst, int i)
{
	t_list	*tmp;

	tmp = (*lst);
	(*lst) = (*lst)->next;
	tmp->next = NULL;
	ft_lstadd_back(lst, tmp);
	if (i == 1)
		ft_printf("rb\n");
}

void	ft_rotate_rotate(t_list **lst_a, t_list **lst_b)
{
	ft_rotate_a(lst_a, 0);
	ft_rotate_b(lst_b, 0);
	ft_printf("rr\n");
}

void	ft_r_rotate_a(t_list **lst, int i)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	tmp2 = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp2->next->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	ft_lstadd_front(lst, tmp);
	(*lst) = tmp;
	if (i == 1)
		ft_printf("rra\n");
}

void	ft_r_rotate_b(t_list **lst, int i)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	tmp2 = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp2->next->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	ft_lstadd_front(lst, tmp);
	(*lst) = tmp;
	if (i == 1)
		ft_printf("rrb\n");
}
