#include "libasm_tester.h"

void	w_strdup(const char *str)
{

	char *ret = ft_strdup(str);
	if (strcmp(str, ret))
	{
		pko("cmp");
		ERR |= ERR_STRDUP_CMP;
	}
	else
		pok("cmp");
	pnl();
}
