/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dadsh_launch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:03:14 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/11 12:52:20 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"







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