/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:22:36 by hguillau          #+#    #+#             */
/*   Updated: 2022/11/24 16:19:01 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_calc_cp_a(t_list **lst_a, t_data *data, int j)
{
	t_list	*tmp;
	int		i;

	tmp = *lst_a;
	i = 0;
	data->cp_a = 0;
	data->move_a = 1;
	data->node_a = tmp->content;
	find_next(j, lst_a, data);
	while (tmp->content != data->to_find)
	{
		tmp = tmp->next;
		i++;
	}
	if (i > data->size_al)
	{
		i = i - ft_lstsize(*lst_a);
		data->move_a = -1;
		if (i < 0)
			i *= -1;
	}
	data->cp_a = i;
	data->node_a = tmp->content;
	return (i);
}

void	ft_calc_cp_b(t_list **lst_a, t_list **lst_b, t_data *data)
{
	t_list	*tmp;

	tmp = *lst_b;
	data->cp_b = 0;
	data->nb_opti = 150000;
	data->move_b = 1;
	data->sens_b = 1;
	data->cp_bis = 0;
	data->node_b = tmp->content;
	while (tmp)
	{
		div_list(lst_a, lst_b, data);
		ft_bbis(data, tmp->content, lst_a, lst_b);
		if (data->nb_cp < data->nb_opti)
		{
			data->nb_opti = data->nb_cp;
			data->node_b = tmp->content;
			data->sens_b = data->move_b;
			data->sens_a = data->move_a;
			data->true_node_a = data->node_a;
		}
	tmp = tmp->next;
	data->cp_b++;
	}
}

void	ft_bbis(t_data *data, int i, t_list **lst_a, t_list **lst_b)
{
	int	coup_a;

	coup_a = ft_calc_cp_a(lst_a, data, i);
	if (data->cp_b > data->size_bl && ft_lstsize(*lst_b) > 1)
	{
		data->cp_bis = data->cp_b - ft_lstsize(*lst_b);
		data->move_b = -1;
		if (data->cp_bis < 0)
			data->cp_bis *= -1;
	}
	else
		data->cp_bis = data->cp_b;
	if (data->move_a == data->move_b)
	{
		if (coup_a > data->cp_bis)
			data->nb_cp = coup_a;
		else if (coup_a < data->cp_bis)
			data->nb_cp = data->cp_bis;
		else
			data->nb_cp = coup_a;
	}
	else
		data->nb_cp = coup_a + data->cp_bis;
}

void	div_list(t_list **lst_a, t_list **lst_b, t_data *data)
{
	data->size_al = (ft_lstsize(*lst_a)) / 2;
	data->size_bl = ft_lstsize(*lst_b) / 2;
	if (ft_lstsize(*lst_a) != data->size_al * 2)
		data->size_al = (ft_lstsize(*lst_a) / 2) + 1;
	if (ft_lstsize(*lst_b) != data->size_bl * 2)
		data->size_bl = (ft_lstsize(*lst_b) / 2) + 1;
}
