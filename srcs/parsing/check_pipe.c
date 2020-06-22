/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 13:51:24 by jereligi          #+#    #+#             */
/*   Updated: 2020/06/22 13:37:46 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_isprint(char c)
{
	if (c >= 33 && c <= 126)
		return (1);
	return (0);
}

static int		additional_read_pipe(t_stock *s)
{
	int		status;
	char	*tmp;

	status = 0;
	tmp = NULL;
	l_printf("pipe> ");
	status = get_next_line(0, &tmp);
	if (status == GNL_LINE_READED || status == GNL_EOF)
		s->user_input = ft_strjoindel(s->user_input, tmp, 3);
	else if (status == GNL_CTRLD)
	{
		s->error_strings = ft_strjoindel(s->error_strings, ERR_PIPE, 1);
		l_printf("%s\n", s->error_strings);
		return (ERR_SYNTAX);
	}
	l_printf("|%s|\n", s->user_input);
	return (check_quote(s));
}

int				check_pipe(t_stock *s)
{
	int i;
	int valid_pipe;

	i = 0;
	valid_pipe = 0;
	while (valid_pipe == 0)
	{
		if (s->user_input[i] == '\0')
			valid_pipe = 1;
		if (s->user_input[i] == '|' && s->user_input[i - 1] != '\\')
		{
			i++;
			while (ft_isprint(s->user_input[i]) == 0 && s->user_input[i])
				i++;
			if (s->user_input[i] == '\0')
			{
				if (additional_read_pipe(s) == ERR_SYNTAX)
					return (ERR_SYNTAX);
				i = 0;
			}
		}
		i++;
	}
	return (0);
}