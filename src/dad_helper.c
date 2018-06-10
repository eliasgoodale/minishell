/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dad_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 14:24:27 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/10 15:07:38 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

t_job	*find_job(pid_t target_pgid, t_job **first_job)
{
	t_job *j;

	j = *first_job;
	while(j && (j->pgid != target_pgid))
		j = j->next;
	return (j);
}

int		job_is_stopped(t_job *j)
{
	t_process *p;

	p = j->first_process;
	while(p)
	{
		if(!p->completed && !p->stopped)
			return (0);
		p = p->next;
	}
}

int		job_is_completed(job *j)
{
	t_process *p;

	p = j->first_process;
	while(p)
	{
		if(!p->completed)
			return (0);
	}
	return (1);
}