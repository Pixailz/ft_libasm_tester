#include "libasm_tester.h"

void	w_write(int fd, char *str, int size)
{
	int	retv[2] = {0};
	int	err[2] = {0};

	ppwrite(fd, str, size);
	retv[0] = write(fd, str, size);
	err[0] = errno;
	retv[1] = ft_write(fd, str, size);
	err[1] = errno;
	if (retv[0] == retv[1])
		pok("retv");
	else
	{
		pko("retv");
		ERR |= ERR_WRITE_RET;
	}
	if (err[0] == err[1])
		pok("err");
	else
	{
		pko("err");
		ERR |= ERR_WRITE_ERR;
	}
	pnl();
}
