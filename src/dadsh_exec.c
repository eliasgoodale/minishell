/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dadsh_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:23:27 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/21 18:49:38 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

#include "../include/cmd_tbl.h"

int		delta_exec(char *path, char **args)
{
	struct stat	fstat;

	if(lstat(path, &fstat) != -1)
	{
		if(S_ISDIR(fstat.st_mode))
		{
			dadsh_cd(args);
			return (1);
		}
		else if(fstat.st_mode & S_IXUSR)
			return(dadsh_run(path, args));
	}
	ft_printf("%s : No such file or directory\n", path);
	return (1);
}

int		inside_cwd(char *path)
{
	VAR(DIR*, dir, opendir("."));
	VAR(t_dirent*, entry, NULL);
	while((entry = readdir(dir)))
	{
		if (ft_strcmp(path, entry->d_name) == 0)
			return (1);
	}
	return (0);
}

char 	*ft_prepend_str(char *prefix, char *suffix)
{
	VAR(char*, ret, NULL);
	VAR(int, i, -1);
	VAR(int, j, -1);
	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(prefix) + ft_strlen(suffix) + 1))))
		ft_printf("prepend str");
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






int		dadsh_exec(t_vector	*line_in)
{
	VAR(int, i, -1);
	VAR(char **, args, NULL);
	if(!(args = normalize_arguments(v->data)))
		return (-1);
	ft_putchar('\n')
	
	if(!line_in->data)
		return (1);
	while(++i < MAX_BUILTINS)
		if (ft_strncmp(line_in->data, t_builtin[i].name, t_builtin[i].namelen) == 0)
			return(g_dadsh_cmds[i](normalize_input(&args[1])));
	return (dadsh_launch(line_in->data));
}






















int		dadsh_help(char **args)
{
	VAR(int, i, -1);
	(void)args;
	ft_printf("Dadshell: v 0.0.1\n");
	ft_printf("Instructional help goes here\n");
	ft_printf("The following builtins are present in this shell:\n");
	while(g_builtin_str[++i])
		ft_printf("%d: %s\n", i + 1, g_builtin_str[i]);
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