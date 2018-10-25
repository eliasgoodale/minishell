/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:48:23 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/24 18:39:57 by egoodale         ###   ########.fr       */
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

void	update_oldpwd(char *oldwd)
{
	VAR(char *, u_env, NULL);
	VAR(char **, u_oldpwd, NULL);
	if (oldwd)
	{
		u_env = ft_strjoin("OLDPWD=", oldwd);
		u_oldpwd = ft_strsplit(u_env, ' ');
		set_env(u_oldpwd);
		ft_freestrarr(u_oldpwd);
		free(u_env);
	}
}

int		cd(char **args)
{
	VAR(char *, envv_path, find_envv("HOME", 1));
	VAR(char *, full_path, NULL);
	VAR(char *, cwd, getcwd(NULL, 0));
	if (envv_path && !args[0])
		full_path = ft_strdup(envv_path);
	else if (envv_path && args[0][0] == '~')
		full_path = ft_prepend_str(envv_path, &args[0][1]);
	else if (!ft_strcmp(args[0], "-") && 
			(envv_path = find_envv("OLDPWD", 1)))
		full_path = ft_strdup(envv_path);
	else
		full_path = ft_strdup(args[0]);
	if (chdir(full_path))
		determine_chdir_error(full_path);
	else
		update_oldpwd(cwd);
	free(full_path);
	free(cwd);
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
