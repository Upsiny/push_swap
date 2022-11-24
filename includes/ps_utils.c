/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:44:55 by hguillau          #+#    #+#             */
/*   Updated: 2022/11/24 16:55:00 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_ps(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	show_lst(t_list **lst)
{
	t_list	*tmp;

	tmp = (*lst);
	while (tmp)
	{
		ft_printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
}

void	check_order(t_list **lst)
{
	t_list	*tmp;

	tmp = (*lst);
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return ;
		tmp = tmp->next;
	}
	exit(0);
}

void	find_bigger(t_list **lst, t_data *data)
{
	t_list	*tmp;

	tmp = *lst;
	data->smaller = tmp->content;
	data->bigger = tmp->content;
	while (tmp)
	{
		if (tmp->content < data->smaller)
			data->smaller = tmp->content;
		if (tmp->content > data->bigger)
			data->bigger = tmp->content;
		tmp = tmp->next;
	}
}

void	find_next(int i, t_list **lst, t_data *data)
{
	t_list	*tmp;

	tmp = *lst;
	find_bigger(lst, data);
	if (i > data->bigger)
	{
		data->to_find = data->smaller;
		return ;
	}
	if (i < data->smaller)
	{
		data->to_find = data->smaller;
		return ;
	}
	while (tmp)
	{
		if (tmp->content > i && tmp->content <= data->bigger)
		{
			data->to_find = tmp->content;
			data->bigger = tmp->content;
		}
		tmp = tmp->next;
	}
}
