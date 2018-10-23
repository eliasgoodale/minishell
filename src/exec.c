/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 11:11:26 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/23 14:58:21 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

int		run(char *path, char **args)
{
	pid_t	pid;

	pid = fork();
	signal(SIGINT, handle_signal);
	if (pid == 0)
		execve(path, args, g_envv);
	else if (pid < 0)
		ft_printf("Fork failed to create a new process.\n");
	wait(&pid);
	free(path);
	return (1);
}

int		launch(char *path, char **args)
{
	struct stat fstat;

	if (~lstat(path, &fstat))
	{
		if (fstat.st_mode & S_IXUSR)
			return (run(path, args));
		else
			ft_printf("minishell: permission denied: %s\n", path);
	}
	else
	{
		ft_printf("dsh: command not found %s\n", path);
		free(path);
	}
	return (1);
}

int		build_path(char **args)
{
	VAR(char *, full_path, NULL);
	VAR(char *, path_envv, get_envv_val("PATH"));
	VAR(char *, search_directory, ft_strtok(path_envv, ":"));
	path_envv = path_envv ? ft_strdup(path_envv) : NULL;
	if (is_in(".", args[0]))
		full_path = ft_strdup(args[0]);
	else
	{
		while (search_directory)
		{
			if (is_in(search_directory, args[0]))
			{
				full_path = ft_prepend_str(search_directory, args[0]);
				break ;
			}
			search_directory = ft_strtok(NULL, ":");
		}
	}
	!full_path ? full_path = ft_strdup(args[0]) : 0;
	free(path_envv);
	return (launch(full_path, args));
}

int		execute(char **args)
{
	VAR(int, i, -1);
	while (++i < BUILTINS)
		if (ft_strcmp(args[0], t_builtin[i].name) == 0)
			return (t_builtin[i].func(&args[1]));
	return (build_path(args));
}
