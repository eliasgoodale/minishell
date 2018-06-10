/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:17:14 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/10 14:01:21 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

void dad_loop(t_process *p, int fd)
{
	char *line;
	char **args;
	int status;

	status = 1;
	while (status)
	{
		ft_printf("\n> ");
		get_next_line(fd, &line);
		args = ft_strsplit(line, ' ');
		status = dadsh_exec(args);
		free(line);
		free(args);
	}
		
}


/*static int		check_bins(char **command)
{
	int				i;
	char			*bin_path;
	char			**path;
	struct stat		f;

	path = ft_strsplit(get_env_var("PATH"), ':');
	i = -1;
	while (path && path[++i])
	{
		if (ft_strstartswith(command[0], path[i]))
			bin_path = ft_strdup(command[0]);
		else
			bin_path = ft_pathjoin(path[i], command[0]);
		if (lstat(bin_path, &f) == -1)
			free(bin_path);
		else
		{
			ft_freestrarr(path);
			return (is_executable(bin_path, f, command));
		}
	}
	ft_freestrarr(path);
	return (0);
}


static char		*parse_env_var(char *str, int pos)
{
	char	*value;
	char	*key;
	char	c;

	key = ft_strnew(1);
	while (str[pos] && !IS_SPACE(str[pos]))
	{
		c = str[pos];
		key = ft_strjoinchcl(key, c);
		pos++;
	}
	if (!(value = get_env_var(key)))
	{
		free(key);
		return (NULL);
	}
	free(key);
	return (value);
*/
int main(int ac, char **av, char **env)
{
	char *ttyfile = av[1];
	int fd = open(ttyfile, O_RDWR);
	init_shell(fd, env);
	dad_loop(fd);
	return (EXIT_SUCCESS);
}