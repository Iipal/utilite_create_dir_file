#ifndef __HEADER_H__
# define __HEADER_H__

# define _GNU_SOURCE

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef char* string;

# define FLAGS_MAX 2
# define FLAGS "df"

# define _SYS_CURRENT_PATH "pwd"
# define _SYS_TOUCH "touch "
# define _SYS_MKDIR "mkdir "

# define ERR_NOARGS "ERROR: Not enought args for start.\n"
# define ERR_TOOMANY_ARGS_NOFLAGS "ERROR: Too many args for non-flags work.\n"
# define ERR_NOMEMORY "ERROR: Not enoght memory in your PC.\n"
# define ERR_UNKNOW_FLAGS "ERROR: Unknow flags.\n"
# define ERR_TOOMANY_FLAGS "ERROR: Too many flags.\n"
# define ERR_DFLAG "ERROR: passing dir name for -d flag.\n"
# define ERR_FFLAG "ERROR: passing file name for -f flag.\n"
# define ERR_FFLAG_AFTER_D "ERROR: passing file name for -f flag after -d.\n"

int		g_is_d;
int		g_is_f;

char	err_mode;
FILE	*err_log;
# define STOP_IF(assert, err_act, ...) {					\
	if (assert) {											\
		fprintf(err_log ? err_log : stderr, __VA_ARGS__);	\
		if (err_mode == 's') abort();						\
		else { err_act; } } }								\


void	ft_action(const string action, const string dir, const string file);
void	ft_noflags_parse(int argc, string *argv);
void	ft_flags_parse(string *flags);

#endif
