/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tbl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:04:35 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/09 16:48:46 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_TBL_H
#define CMD_TBL_H
#define MAX_BUILTINS 3

char *builtin_str[MAX_BUILTINS] = {
	"cd",
	"help",
	"exit"
};

typedef int (*t_builtin)(char**);

enum e_builtin
{
	CD,
	HELP,
	EXIT
};

t_builtin g_dadsh_cmds[MAX_BUILTINS] = {
	&dadsh_cd,
	&dadsh_help,
	&dadsh_exit
};

#endif
