/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolfrum <gwolfrum@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:20:19 by gwolfrum          #+#    #+#             */
/*   Updated: 2025/12/02 15:20:46 by gwolfrum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	num_nodes;

	num_nodes = 0;
	while (lst)
	{
		lst = lst->next;
		num_nodes ++;
	}
	return (num_nodes);
}
