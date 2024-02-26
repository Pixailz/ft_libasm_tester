#include "libasm_tester.h"

void	w_strcpy(char *src)
{
	char	buffer[100] = {0};
	char	*ptr;

	ptr = ft_strcpy(buffer, src);
	ptest(src);
	if (ptr == buffer)
		pok("ptr");
	else
	{
		pko("ptr");
		ERR |= ERR_STRCPY_PTR;
	}
	if (!strcmp(buffer, src))
		pok("cmp");
	else
	{
		pko("cmp");
		ERR |= ERR_STRCPY_CMP;
	}
	pnl();
}
