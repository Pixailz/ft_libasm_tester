#include "libasm_tester.h"

#define A_LONG_STRING \
	"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" \
	"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" \
	"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" \
	"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" \
	"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" \
	"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" \
	"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" \
	"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" \
	"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" \
	"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" \

void	t_strlen(void)
{
	ppart("ft_strlen");
	w_strlen(NULL);
	w_strlen("1234");
	w_strlen("\x00test");
	w_strlen("");
	w_strlen(A_LONG_STRING);
	pnl();
}

void	t_strcpy(void)
{
	ppart("ft_strcpy");

	// w_strcpy(NULL); // SEGFAULT
	w_strcpy("1234");
	w_strcpy("\x00test");
	w_strcpy("");
	w_strcpy(A_LONG_STRING);

	pnl();
}

void	t_strcmp(void)
{
	ppart("ft_strcmp");

	w_strcmp("1234", "1234", 'e');
	// w_strcmp(NULL, "\x00", 'e');
	w_strcmp("1234", "4321", 'l');
	w_strcmp("4321", "1234", 'g');
	w_strcmp("", "", 'e');
	w_strcmp("A", "", 'g');
	w_strcmp("", "A", 'l');

	pnl();
}

void	t_write(void)
{
	ppart("ft_write");
	w_write(FD_IN, "TEST", 4);
	w_write(FD_DEVNULL, "TEST", 4);
	w_write(-1, "TEST", 4);
	w_write(FD_IN, "", 4);
	w_write(FD_IN, "TEST", 1);

	pnl();
}

void	t_read(void)
{
	ppart("ft_read");
	w_read(0, 10);
	w_read(FD_DEVNULL, 10);
	pnl();
}

void	t_strdup(void)
{
	ppart("ft_strdup");
	w_strdup("Hello");
	w_strdup("");
	// w_strdup(NULL); // SEGFAULT on both libc and libasm ...
	w_strdup(A_LONG_STRING);

	pnl();
}
