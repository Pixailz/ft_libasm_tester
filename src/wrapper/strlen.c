#include "libasm_tester.h"

void	w_strlen(char *str)
{
	unsigned int mine_size = ft_strlen(str);
	unsigned int real_size = 0;

	if (str)
		real_size = strlen(str);
	ptest(str);
	if (real_size == mine_size)
		pok("size");
	else
	{
		pko("size");
		ERR |= ERR_STRLEN;
	}
	puts("");
}
