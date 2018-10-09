P = create
L = lib/libcreate.a
CC = c99
CL = ar rcs

P_INC = -include lib/includes/libcreate.h
CFLAGS = -g -Wall -Wextra -Werror -o

DIR_SRCS = lib/srcs/

OBJ_MKDIR = $(shell mkdir lib/srcs/obj)
OBJ_DIR = $(DIR_SRCS)obj/
OBJ = $(OBJ_DIR)ft_noflags_parse.o $(OBJ_DIR)ft_flags_parse.o

DEL = rm -rfv

all: $L $P

$L:
	$(OBJ_MKDIR)
	$(CC) $(DIR_SRCS)ft_noflags_parse.c -c $(P_INC) $(CFLAGS) $(OBJ_DIR)ft_noflags_parse.o
	$(CC) $(DIR_SRCS)ft_flags_parse.c -c $(P_INC) $(CFLAGS) $(OBJ_DIR)ft_flags_parse.o
	$(CL) $L $(OBJ)
$P:
	$(CC) main.c $(P_INC) $(CFLAGS) $P -Llib/. -lcreate

clean:
	@$(DEL) $(OBJ_DIR)

fclean: clean
	@$(DEL) $L
	@$(DEL) $P

re: fclean all

.PHONY: re fclean all $P $L all
