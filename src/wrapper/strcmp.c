#include "libasm_tester.h"

void	w_strcmp(char *s1, char *s2, char mode)
{
	int retv = ft_strcmp(s1, s2);

	pstrcmp(s1, s2, mode);
	if (mode == 'e' && retv == 0)
		pok(NULL);
	else if (mode == 'l' && retv < 0)
		pok(NULL);
	else if (mode == 'g' && retv > 0)
		pok(NULL);
	else
	{
		pko(NULL);
		ERR |= ERR_STRCMP_RET;
	}
	pnl();
}
