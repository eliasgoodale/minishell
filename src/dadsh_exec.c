/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dadsh_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:23:27 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/13 18:13:07 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

#include "../include/cmd_tbl.h"

char 	*ft_prepend_str(char *prefix, char *suffix)
{
	VAR(char*, ret, NULL);
	VAR(int, i, -1);
	VAR(int, j, -1);
	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(prefix) + ft_strlen(suffix) + 1))))
		throw_err("prepend str");
	while(prefix[++i])
		ret[i] = prefix[i];
	while(suffix[++j])
		ret[i++] = suffix[j];
	ret[i] = '\0';
	return (ret);
}

int		is_in_bins(char *command)
{
    VAR(DIR*, bin_folder, opendir("/bin/"));
    VAR(t_dirent *, entry, NULL);
    while ((entry = readdir(bin_folder)))
        if (ft_strcmp(entry->d_name, command) == 0)
            return (1);
    return (0);
}

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
	char *path;

	if (is_in_bins(args[0]))
		path = ft_prepend_str("/bin/" , args[0]);
	else
		path = ft_strdup(args[0]);
	if(lstat(path, &fstat) != -1)
	{
		if(S_ISDIR(fstat.st_mode))
		{
			dadsh_cd(args);
			return (0);
		}
		else if(fstat.st_mode & S_IXUSR)
			return(dadsh_run(path, args));
	}
	return(1);
}

int		dadsh_exec(char **args)
{
	VAR(int, i, -1);
	if(args[0] == NULL)
		return (1);
	while(++i < MAX_BUILTINS)
		if (ft_strcmp(args[0], builtin_str[i]) == 0)
			return(g_dadsh_cmds[i](args));
	return (dadsh_launch(args));
}

int		dadsh_help(char **args)
{
	VAR(int, i, -1);
	(void)args;
	ft_printf("Dadshell: v 0.0.1\n");
	ft_printf("Instructional help goes here\n");
	ft_printf("The following builtins are present in this shell:\n");
	while(builtin_str[i])
		ft_printf("%d: %s\n", i + 1, builtin_str[i]);
	ft_printf("Use man command for information on other programs\n");
	return (1);
}

int		dadsh_env(char **args)
{
	(void)args;
	print_env();
	return (1);
}
int		dadsh_exit(char **args)
{
	(void)args;
	return (0);
}