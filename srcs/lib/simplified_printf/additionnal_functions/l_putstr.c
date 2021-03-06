/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_putstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lobbyra <Lobbyra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:23:57 by Lobbyra           #+#    #+#             */
/*   Updated: 2020/01/28 13:15:34 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		l_putstr(char *s)
{
	if (s)
		while (*s)
			write(1, s++, 1);
}
