/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:14:10 by brda-sil          #+#    #+#             */
/*   Updated: 2024/02/26 21:24:05 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_tester.h"

flags	ERR = ERR_NOERR;
int		FD_LOG;
int		FD_IN;
int		FD_DEVNULL;

# define LOG_PERM 00755

int	redirect_to_devnull(void)
{
	FD_IN = dup(1);
	close(1);
	FD_DEVNULL = open("/dev/null", O_RDWR);
	dup2(FD_DEVNULL, 1);
	return (0);
}

int	init_data()
{
	// FD_LOG = open("exec.log", O_APPEND | O_CREAT | O_WRONLY, LOG_PERM);
	FD_LOG = open("exec.log", O_TRUNC | O_CREAT | O_WRONLY, LOG_PERM);
	if (FD_LOG < 0)
		return (1);
	if (redirect_to_devnull())
		return (1);
	return (0);
}

void	free_data()
{
	close(FD_DEVNULL);
	close(FD_IN);
	if (FD_LOG > 0)
		close(FD_LOG);
}

int	main(void)
{
	if (init_data())
		return (1);
	t_strlen();
	t_strcpy();
	t_strcmp();
	t_write();
	t_read();
	// t_strdup();
	free_data();
	return (0);
}
