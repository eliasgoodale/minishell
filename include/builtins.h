/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:15:00 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/23 13:18:31 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef BUILTINS_H
#	define BUILTINS_H

#include "dadshell.h"

static struct	s_builtin
{
	char		*name;
	t_builtinfunc	func;
}				t_builtin[BUILTINS] = {
	{"cd", &cd},
	{"echo", &echo},
	{"env", &print_env},
	{"setenv", &set_env},
	{"unsetenv", &unset_env},
	{"help", &display_help},
	{"exit", &exit_shell}
};

#	endif