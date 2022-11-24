/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:51:30 by hguillau          #+#    #+#             */
/*   Updated: 2022/11/24 17:08:20 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data {
	int	smaller;
	int	bigger;
	int	to_find;
	int	nb_cp;
	int	nb_opti;
	int	cp_a;
	int	cp_b;
	int	node_a;
	int	true_node_a;
	int	node_b;
	int	move_a;
	int	move_b;
	int	sens_a;
	int	sens_b;
	int	cp_bis;
	int	size_al;
	int	size_bl;
}		t_data;

////////////// fonctions /////////////////
void	ft_algo_3(t_list **lst_a);
void	ft_algo(t_list **lst_a, t_list **lst_b, t_data *data);
void	ft_order_lst(t_list **lst, t_data *data);
int		ft_calc_cp_a(t_list **lst, t_data *data, int j);
void	ft_calc_cp_b(t_list **lst_a, t_list **lst_b, t_data *data);
void	div_list(t_list **lst_a, t_list **lst_b, t_data *data);

////////////// norminette ///////////////////
void	ft_bbis(t_data *data, int i, t_list **lst_a, t_list **lst_b);
void	ft_sens_rotate(t_list **lst_a, t_list **lst_b, t_data *data);
void	ft_sens_r_rotate(t_list **lst_a, t_list **lst_b, t_data *data);
void	ft_reste_algo(t_list **lst_a, t_list **lst_b, t_data *data);

////////////// Utils ////////////////////
void	ft_error_ps(void);
void	show_lst(t_list **lst);
void	check_order(t_list **lst);
void	find_bigger(t_list **lst, t_data *data);
void	find_next(int i, t_list **lst, t_data *data);

////////////// Mouvements ///////////////
void	ft_swap_a(t_list **lst);
void	ft_swap_b(t_list **lst);
void	ft_swap_swap(t_list **lst_a, t_list **lst_b);
void	ft_push_a(t_list **lst_a, t_list **lst_b);
void	ft_push_b(t_list **lst_a, t_list **lst_b);
void	ft_rotate_a(t_list **lst, int i);
void	ft_rotate_b(t_list **lst, int i);
void	ft_rotate_rotate(t_list **lst_a, t_list **lst_b);
void	ft_r_rotate_a(t_list **lst, int i);
void	ft_r_rotate_b(t_list **lst, int i);
void	ft_rrr(t_list **lst_a, t_list **lst_b);

#endif
