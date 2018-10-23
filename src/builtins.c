/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:48:23 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/23 13:33:07 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

void	determine_chdir_error(char *path)
{
	struct stat fstat;

	if (~stat(path, &fstat))
	{
		if (!S_ISDIR(fstat.st_mode))
			ft_printf("cd: is not a directory: %s\n", path);
		else if (!(fstat.st_mode & S_IROTH))
			ft_printf("cd: permission denied: %s\n", path);
	}
	else
		ft_printf("cd: no such file or directory: %s\n", path);
}

int		cd(char **args)
{
	VAR(char *, home_path, get_envv_val("HOME"));
	VAR(char *, full_path, NULL);
	if (args[0] == NULL)
		chdir(home_path);
	else
	{
		if (args[0][0] == '~')
		{
			full_path = ft_prepend_str(home_path, &args[0][1]);
			if (chdir(full_path))
				determine_chdir_error(full_path);
			free(full_path);
		}
		else if (chdir(args[0]))
			determine_chdir_error(args[0]);
	}
	return (1);
}

int		print_env(char **args)
{
	int		i;

	i = -1;
	(void)args;
	while (g_envv[++i])
		ft_printf("%s\n", g_envv[i]);
	return (1);
}

int		display_help(char **args)
{
	(void)args;
	ft_printf("Dad Shell: v 1.0.0\n");
	ft_printf("Use man command for information on programs\n");
	return (1);
}

int		exit_shell(char **args)
{
	(void)args;
	return (0);
}
