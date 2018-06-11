/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tbl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:04:35 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/10 16:45:03 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_TBL_H
#define CMD_TBL_H
#define MAX_BUILTINS 3

char *builtin_str[MAX_BUILTINS] = {
	"cd",
	"echo",
	"env",
	"setenv",
	"unsetenv",
	"help",
	"exit"
};

typedef int (*t_builtin)(char**);

t_builtin g_dadsh_cmds[MAX_BUILTINS] = {
	&dadsh_cd,
	&dadsh_echo,
	&dadsh_env,
	&dadsh_setenv,
	&dadsh_unsetenv,
	&dadsh_help,
	&dadsh_exit

};

#endif
