/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:14:10 by brda-sil          #+#    #+#             */
/*   Updated: 2024/02/25 18:08:58 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_tester.h"

flags ERR = ERR_NOERR;

/* MAIN */
void	t_strlen(void)
{
	ppart("ft_strlen");
	w_strlen(NULL);
	w_strlen("1234");
	w_strlen("\x00test");
}

void	t_strcpy(void)
{
	ppart("ft_strcpy");
	w_strcpy("1234");
}

void	t_strcmp(void)
{
	ppart("ft_strcmp");
	w_strcmp("1234", "1234", 'e');
	w_strcmp("1234", "4321", 'l');
	w_strcmp("4321", "1234", 'g');
}

void	t_write(void)
{
	ppart("ft_write");
	w_write(1, "Hello World\n", 13);
	w_write(-1, "Hello World\n", 13);
}

void	t_read(void)
{
	ppart("ft_read");
	// w_read(0, 10);
}

void	t_strdup(void)
{
	ppart("ft_strdup");
	w_strdup("Hello");
	w_strdup("");
	// w_strdup(NULL); // SEGFAULT on both libc and libasm ...
}

int	main(void)
{
	t_strlen();
	// t_strcpy();
	// t_strcmp();
	// t_write();
	// t_read();
	// t_strdup();
	return (0);
}
