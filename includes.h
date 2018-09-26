#ifndef C_HEADER_H
# define C_HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define _CURRENT_DIR "."
# define _TOUCH "touch "
# define _MKDIR "mkdir "

# define ECHO_RED(msg) "echo \"\033[0;31m" msg "\033[0m\""

# define ERR_MSG_SYS "Something wrong.\n" \
	"Maybe this programm hasn't access to do something on your pc.\n"
# define ERR_MSG_MEM "Something wrong.\n" \
	"Maybe not enought memory on your PC.\n"
# define ERR_MSG_LESS_ARGS "Something wrong.\n" \
	"Not enought argument's.\n"
# define ERR_MSG_2MUCH_ARGS "Something wrong.\n" \
	"Too much argument's.\n"

#endif
