/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dadsh_launch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:03:14 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/21 17:18:24 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"


static int dadsh_run(char *path, char **args)
{
	pid_t	pid;
	char	*bin_path;

	pid = fork();
	signal(SIGINT, dad_psignal);
	if (pid == 0) 
		execvp(path, args);
	else if (pid < 0)
	{
		free(path);
		ft_printf("Fork failed to create a new process.");
		return (-1);
	}
	wait(&pid);
	if (path)
		free(path);
	return (1);
}

int		dadsh_launch(char **args)
{
	VAR(char *, full_path, NULL);
	VAR(char*, path_envv, get_envv_val("PATH"));
	if (!inside_cwd(args[0]) && is_in_bins(args[0]))
		full_path = path_envv ? ft_prepend_str(path_envv, args[0]) :
								ft_prepend_str("/bin/", args[0]);
	else
		full_path = ft_strdup(args[0]);
	return(delta_exec(full_path, args));

}




/*
int		dadsh_launch(char **args)
{
	pid_t pid;
	pid_t wpid;
	int status;

	pid = fork();
	if (pid < 0)
		ft_printf("fork error");
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			ft_printf("dadsh");
	}
	else
	{
		while(!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}*/