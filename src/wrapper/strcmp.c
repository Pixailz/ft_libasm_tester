#include "libasm_tester.h"

void	w_strcmp(char *s1, char *s2, char mode)
{
	int retv = ft_strcmp(s1, s2);

	if (mode == 'e' && retv == 0)
		pok("retv == 0");
	else if (mode == 'l' && retv < 0)
		pok("retv < 0");
	else if (mode == 'g' && retv > 0)
		pok("retv > 0");
	else
	{
		pko("retv > 0");
		ERR |= ERR_STRCMP_RET;
	}
}
