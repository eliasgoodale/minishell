/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dadsh_launch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:03:14 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/10 19:25:01 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

void	throw_err(char *msg)
{
	write(1, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

static int dadsh_run(char *path, char **args)
{
	pid_t	pid;
	
	pid = fork();
	signal(SIGINT, proc_signal_handler);
	if (pid == 0)
		execve(path, args, g_envv);
	else if (pid < 0)
	{
		free(path);
		throw_err("Fork failed to create a new process.");
		return (-1);
	}
	wait(&pid);
	if (path)
		free(path);
	return (1);
}

int		dadsh_launch(char **args)
{
	struct stat	fstat;
	
	if(lstat(args[0], &fstat) != -1)
	{
		if(S_ISDIR(fstat.st_mode))
		{
			dadsh_cd(args);
			return (0);
		}
		else if(fstat.st_mode & S_IXUSR)
			return(dadsh_run(ft_strndup(args[0]), args))
	}
}




/*
int		dadsh_launch(char **args)
{
	pid_t pid;
	pid_t wpid;
	int status;

	pid = fork();
	if (pid < 0)
		throw_err("fork error");
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			throw_err("dadsh");
	}
	else
	{
		while(!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}*/