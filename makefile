CFLAGS = -include includes.h -g -Wall -Ofast -o
CC = c99

DEL = rm -rf

ECHO_GREEN = \033[0;32m
ECHO_RED = \033[0;31m
ECHO_WHITE = \033[0m

all:
	@$(CC) main.c $(CFLAGS) create
	@echo "$(ECHO_GREEN)success.$(ECHO_WHITE)"
clean:
	@$(DEL) create*
	@echo "$(ECHO_RED)executable file deleted.$(ECHO_WHITE)"
help_make:
	@echo "just type: $(ECHO_GREEN)make$(ECHO_WHITE) for create executable file."
	@echo "for delete executable file type: $(ECHO_RED)make clean$(ECHO_WHITE)"
help_create:
	@echo "   You can write 1 or 2 args for this programm."
	@echo "If you write only 1 args for this programm:"
	@echo " "
	@echo " If you type argument without any extension - programm will create directory with your name."
	@echo "  $(ECHO_GREEN)example:$(ECHO_WHITE) ./create dir_name"
	@echo "   $$ mkdir dir_name"
	@echo " "
	@echo " If you type argument with any extension - programm will create file with your name and extension."
	@echo "  $(ECHO_GREEN)example:$(ECHO_WHITE) ./create main.c"
	@echo "   $$ touch main.c"
	@echo " "
	@echo "If you write 2 args programm will create directory with your name and"\
	" 1 file inside this directory with your name"
	@echo " $(ECHO_GREEN)example:$(ECHO_WHITE) ./create dir_name main.c"
	@echo "  $$ mkdir dir_name"
	@echo "  $$ touch dir_name/main.c"
	@echo " "
.PHONY: all clean help_make help_create
