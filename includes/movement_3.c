/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:47:25 by hguillau          #+#    #+#             */
/*   Updated: 2022/11/12 13:12:36 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_list **lst_a, t_list **lst_b)
{
	ft_r_rotate_a(lst_a, 0);
	ft_r_rotate_b(lst_b, 0);
	ft_printf("rrr\n");
}