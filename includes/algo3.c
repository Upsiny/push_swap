/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:19:07 by hguillau          #+#    #+#             */
/*   Updated: 2022/11/24 16:33:22 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sens_rotate(t_list **lst_a, t_list **lst_b, t_data *data)
{
	while ((*lst_a)->content != data->true_node_a
		&& (*lst_b)->content != data->node_b)
		ft_rotate_rotate(lst_a, lst_b);
	while ((*lst_a)->content != data->true_node_a \
			|| (*lst_b)->content != data->node_b)
	{
		if ((*lst_a)->content != data->true_node_a)
			ft_rotate_a(lst_a, 1);
		if ((*lst_b)->content != data->node_b)
			ft_rotate_b(lst_b, 1);
	}
}

void	ft_sens_r_rotate(t_list **lst_a, t_list **lst_b, t_data *data)
{
	while (((*lst_a)->content != data->true_node_a \
		&& (*lst_b)->content != data->node_b))
		ft_rrr(lst_a, lst_b);
	while ((*lst_a)->content != data->true_node_a \
		|| (*lst_b)->content != data->node_b)
	{
		if ((*lst_a)->content != data->true_node_a)
			ft_r_rotate_a(lst_a, 1);
		if ((*lst_b)->content != data->node_b)
			ft_r_rotate_b(lst_b, 1);
	}
}

void	ft_reste_algo(t_list **lst_a, t_list **lst_b, t_data *data)
{
	while ((*lst_a)->content != data->true_node_a \
		|| (*lst_b)->content != data->node_b)
	{
		if (data->sens_a > 0 && (*lst_a)->content != data->true_node_a)
			ft_rotate_a(lst_a, 1);
		if (data->sens_b < 0 && (*lst_b)->content != data->node_b)
			ft_r_rotate_b(lst_b, 1);
		if ((*lst_b)->content != data->node_b && data->sens_b > 0)
			ft_rotate_b(lst_b, 1);
		if ((*lst_a)->content != data->true_node_a && data->sens_a < 0)
			ft_r_rotate_a(lst_a, 1);
	}
}
