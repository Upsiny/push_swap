/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:41:59 by hguillau          #+#    #+#             */
/*   Updated: 2022/11/24 17:10:03 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	tab_to_list(int *tab, t_list **lst, int j)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (i < j)
	{
		tmp = ft_lstnew(tab[i]);
		ft_lstadd_back(lst, tmp);
		i++;
	}
	check_order(lst);
}

int	ft_count_arg(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	*ft_check_dup(int *tab, int size)
{
	int	i;
	int	j;
	int	size2;

	i = 0;
	while (size--)
	{
		j = i + 1;
		size2 = size;
		while (size2--)
		{
			if (tab[i] == tab[j])
			{
				ft_error_ps();
			}
			j++;
		}
		i++;
	}
	return (tab);
}

void	ft_switch_var(char **tab, t_list **lst)
{
	int	*tab_int;
	int	i;
	int	j;

	i = 0;
	j = ft_count_arg(tab);
	tab_int = malloc((j - i) * sizeof (int *));
	while (tab[i])
	{
		tab_int[i] = ft_atoi(tab[i]);
		i++;
	}
	ft_check_dup(tab_int, i);
	tab_to_list(tab_int, lst, j);
	free(tab_int);
}

int	main(int ac, char **av)
{
	char	**zoui;
	t_list	*lst_a;
	t_list	*lst_b;
	int		i;
	t_data	data;

	lst_a = NULL;
	lst_b = NULL;
	i = 0;
	if (ac < 2)
		ft_error_ps();
	else if (ac == 2)
	{
		if (ft_strlen(av[1]) == 0)
			return (0);
		zoui = ft_split(av[1], ' ');
		ft_switch_var(zoui, &lst_a);
		free(zoui);
	}
	else
		ft_switch_var(av + 1, &lst_a);
	if (ft_lstsize(lst_a) >= 3)
		ft_algo(&lst_a, &lst_b, &data);
	else
		ft_order_lst(&lst_a, &data);
}
