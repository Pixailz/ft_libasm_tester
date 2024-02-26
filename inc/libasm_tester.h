#ifndef LIBASM_TESTER_H
# define LIBASM_TESTER_H

/*
 dprintf()
 printf()
 puts()
 */
#include <stdio.h>

/*
 strlen()
 strcmp()
 */
#include <string.h>

/*
 errno
 */
#include <errno.h>

/*
 write()
 */
#include <unistd.h>

/*
 open()
 */
#include <fcntl.h>

/*
 calloc()
 */
#include <stdlib.h>

#include "libasm.h"
#include "ansi.h"

# define COL_RESULT		45

/* ERR STATUS */
# define ERR_NOERR				1UL<<0

# define ERR_STRLEN				1UL<<1

# define ERR_STRCPY_PTR			1UL<<2
# define ERR_STRCPY_CMP			1UL<<3

# define ERR_STRCMP_RET			1UL<<4

# define ERR_WRITE_RET			1UL<<5
# define ERR_WRITE_ERR			1UL<<6

# define ERR_READ_RET			1UL<<7
# define ERR_READ_ERR			1UL<<8
# define ERR_READ_BUF			1UL<<9

# define ERR_STRDUP_CMP			1UL<<10

typedef unsigned int			flags;

// GLOBAL FOR STATUS
extern flags	ERR;
// GLOBAL FOR FD_LOG
extern int		FD_LOG;
extern int		FD_IN;
extern int		FD_DEVNULL;

// PROTOS

	// PRINT
void	pnl(void);
int		padd(int fd, int col, int size);
void	ppart(char *s);
void	ptest(char *s);
void	pstrcmp(char *s1, char *s2, char mode);
size_t	intlen(int n);
void	ppwrite(int fd, char *str, int size);
void	ppread(int fd, int size);
void	pok(char *s);
void	pko(char *s);
void	perrno(char *k, int err);

	// WRAPPER
void	w_read(int fd, int size);
void	w_strcmp(char *s1, char *s2, char mode);
void	w_strcpy(char *src);
void	w_strdup(const char *str);
void	w_strlen(char *str);
void	w_write(int fd, char *str, int size);

	// TEST
void	t_read(void);
void	t_strcmp(void);
void	t_strcpy(void);
void	t_strdup(void);
void	t_strlen(void);
void	t_write(void);

#endif // LIBASM_TESTER_H
