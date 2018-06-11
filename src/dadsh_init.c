/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dadsh_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 19:17:38 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/11 12:46:24 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"



/*void init_shell(int fd, char **env)
{
	struct termios shell_tmodes;
	pid_t shell_pgid;
	int shell_terminal = fd;
	int shell_is_interactive = isatty(shell_terminal);

	if (shell_is_interactive)
	{
		//while (tcgetpgrp(shell_terminal) != (shell_pgid = getpgrp()))
		//	kill(- shell_pgid, SIGTTIN);
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGTSTP, SIG_IGN);
		signal(SIGTTIN, SIG_IGN);
		signal(SIGTTOU, SIG_IGN);
		signal(SIGCHLD, SIG_IGN);
		shell_pgid = getpid();
		if (setpgid(shell_pgid, shell_pgid) < 0)
		{
			throw_err("Couldn't put the shell in its own process group");
			exit(1);
		}
		tcsetpgrp(shell_terminal, shell_pgid);
		tcgetattr(shell_terminal, &shell_tmodes);
		
	}
}*/