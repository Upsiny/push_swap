/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:00:33 by hguillau          #+#    #+#             */
/*   Updated: 2022/11/24 16:42:03 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo_3(t_list **lst_a)
{
	if ((*lst_a)->content > (*lst_a)->next->content
		&& (*lst_a)->content < (*lst_a)->next->next->content)
		ft_swap_a(lst_a);
	else if ((*lst_a)->content < (*lst_a)->next->content
		&& (*lst_a)->content > (*lst_a)->next->next->content)
		ft_r_rotate_a(lst_a, 1);
	else if ((*lst_a)->content < (*lst_a)->next->content
		&& (*lst_a)->next->content > (*lst_a)->next->next->content)
	{
		ft_swap_a(lst_a);
		ft_rotate_a(lst_a, 1);
	}
	else if ((*lst_a)->content > (*lst_a)->next->content
		&& (*lst_a)->content > (*lst_a)->next->next->content
		&& (*lst_a)->next->content < (*lst_a)->next->next->content)
		ft_rotate_a(lst_a, 1);
	else if ((*lst_a)->content > (*lst_a)->next->content
		&& (*lst_a)->content > (*lst_a)->next->next->content
		&& (*lst_a)->next->content > (*lst_a)->next->next->content)
	{
		ft_rotate_a(lst_a, 1);
		ft_swap_a(lst_a);
	}
}

void	ft_order_lst(t_list **lst, t_data *data)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = ft_lstsize(*lst);
	j = 0;
	tmp = *lst;
	find_bigger(lst, data);
	while (tmp->content != data->smaller)
	{
		j++;
		tmp = tmp->next;
	}
	if (j >= i / 2)
	{
		while ((*lst)->content != data->smaller)
			ft_r_rotate_a(lst, 1);
	}
	else
	{
		while ((*lst)->content != data->smaller)
			ft_rotate_a(lst, 1);
	}
}

void	ft_algo(t_list **lst_a, t_list **lst_b, t_data *data)
{
	data->sens_b = 1;
	while (ft_lstsize(*lst_a) > 3)
		ft_push_b(lst_a, lst_b);
	ft_algo_3(lst_a);
	while (ft_lstsize(*lst_b) > 0)
	{
		ft_calc_cp_b(lst_a, lst_b, data);
		if (data->sens_b > 0 && data->sens_a > 0)
			ft_sens_rotate(lst_a, lst_b, data);
		else if (data->sens_b < 0 && data->sens_a < 0)
			ft_sens_r_rotate(lst_a, lst_b, data);
		else
			ft_reste_algo(lst_a, lst_b, data);
		ft_push_a(lst_a, lst_b);
	}
	ft_order_lst(lst_a, data);
}
