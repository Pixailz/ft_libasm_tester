#include "libasm_tester.h"

/* PRINT */
void	pnl(void) { dprintf(FD_LOG, "\n"); }

// 3 + 6 + 2
# define PADD_TEST		11
// 3 + 6 + 4 + 4
# define PADD_STRCMP	17
// 3 + 6 + 2 + 11 + 4 + 9
# define PADD_WRITE		35
// 3 + 6 + 8 + 9
# define PADD_READ		26

int	padd(int fd, int col, int size)
{
	int		s = (size == 0 ? COL_RESULT : size) - col - 1;
	if (s <= 0)
	{
		printf("\n");
		return (1);
	}
	char	*tmp = calloc(sizeof(char), s + 1);

	if (!tmp)
		exit(1);
	for (int i = 0; i < s; i++)
		tmp[i] = ' ';
	write(fd, tmp, s);
	free(tmp);
	return (s);
}

void	ppart(char *s)
{
	dprintf(FD_LOG, "%s%s\n", P_PART, s);
}

void	ptest(char *s)
{
	dprintf(FD_LOG, "   %s'%s'", P_TEST, s);
	padd(FD_LOG, PADD_TEST + strlen(!s ? "(null)" : s), 0);
}

void	pstrcmp(char *s1, char *s2, char mode)
{
	size_t	s_len = strlen(!s1 ? "(null)" : s1) + strlen(!s2 ? "(null)" : s2);

	dprintf(FD_LOG, "   %s'%s'", P_TEST, s1);
	if (mode == 'e')
		dprintf(FD_LOG, " == ");
	else if (mode == 'l')
		dprintf(FD_LOG, "  < ");
	else if (mode == 'g')
		dprintf(FD_LOG, "  > ");
	else
		dprintf(FD_LOG, "  ? ");
	dprintf(FD_LOG, "'%s'", s2);
	padd(FD_LOG, PADD_STRCMP + s_len, 0);
}

size_t	intlen(int n)
{
	int	i = n == 0 ? 1 : 0;

	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ppwrite(int fd, char *str, int size)
{
	dprintf(FD_LOG, "   %swrite from '%s' to %d of size %d", P_TEST, str, fd, size);
	padd(FD_LOG, PADD_WRITE + intlen(fd) + strlen(!str ? "(null)" : str) + intlen(size), 0);
}

void	ppread(int fd, int size)
{
	dprintf(FD_LOG, "   %sread in %d of size %d", P_TEST, fd, size);
	padd(FD_LOG, PADD_READ + intlen(fd) + intlen(size), 0);
}

void	pok(char *s)
{ if (!s) dprintf(FD_LOG, "%s", P_OK);
  else dprintf(FD_LOG, "[%s%s%s]", GRE, s, RST); }

void	pko(char *s)
{ if (!s) dprintf(FD_LOG, "%s", P_KO);
  else dprintf(FD_LOG, "[%s%s%s]", RED, s, RST); }

void	perrno(char *k, int err)
{ dprintf(FD_LOG, "[%serrno%s] %s%s%d", BLU, RST, k, SEP, err); }
