#include "libasm_tester.h"

/* PRINT */
void	ppart(char *s)
{ printf("%s%s\n", P_PART, s); }

void	ptest(char *s)
{ printf("   %s'%s'%s", P_TEST, s, GOTO_RESULT); }

void	pok(char *s)
{ if (!s) printf("%s", P_OK);
  else printf("[%s%s%s]", GRE, s, RST); }

void	pko(char *s)
{ if (!s) printf("%s", P_KO);
  else printf("[%s%s%s]", RED, s, RST); }

void	perrno(char *k, int err)
{ printf("[%serrno%s] %s%s%d", BLU, RST, k, SEP, err); }
