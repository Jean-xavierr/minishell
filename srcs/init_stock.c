/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:26:06 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/18 15:24:03 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_stock	*panic_init_stock(t_stock *stock)
{
	if (stock->envp)
		ft_freestrs(stock->envp);
	if (stock)
		free(stock);
	return (NULL);
}

t_stock			*init_stock(char **envp)
{
	t_stock	*new;

	if (!(new = (t_stock*)malloc(sizeof(t_stock))))
		return (NULL);
	if (!(new->envp = ft_strarrdup(envp)))
		return (panic_init_stock(new));
	new->jobs = NULL;
	new->pipes = NULL;
	new->error_strings = NULL;
	return (new);
}