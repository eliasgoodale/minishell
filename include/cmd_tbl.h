/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tbl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:04:35 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/18 11:10:40 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_TBL_H
#define CMD_TBL_H
#define MAX_BUILTINS 7

static struct s_builtin
{
	char 		*name;
	t_dad_func	dad_func;
}	t_builtin[] = {
	{"cd", &dadsh_cd},
	{"echo", &dadsh_echo},
	{"env", &dadsh_env},
	{"setenv", &dadsh_setenv},
	{"unsetenv", &dadsh_unsetenv},
	{"help", &dadsh_help},
	{"exit", &dadsh_exit}
};


#endif
