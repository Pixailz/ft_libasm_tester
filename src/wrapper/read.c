#include "libasm_tester.h"

void	w_read(int fd, int size)
{
	char	buff1[0x42] = {0};
	char	buff2[0x42] = {0};
	int		err[2] = {0};
	int		retv[2] = {0};

	ppread(fd, size);
	retv[0] = read(fd, buff1, size);
	err[0] = errno;
	retv[1] = ft_read(fd, buff2, size);
	err[1] = errno;
	if (retv[0] == retv[1])
		pok("retv");
	else
	{
		pko("retv");
		ERR |= ERR_READ_RET;
	}
	if (err[0] == err[1])
		pok("err");
	else
	{
		pko("err");
		ERR |= ERR_READ_ERR;
	}
	if (!strcmp(buff1, buff2))
		pok("buff");
	else
	{
		pko("buff");
		ERR |= ERR_READ_BUF;
	}
	pnl();
}
