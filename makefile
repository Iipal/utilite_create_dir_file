CFLAGS = -include headers.h -g -Wall -Ofast -o
CC = c99

DEL = rm -rf

ECHO = echo -e
ECHO_GREEN = \033[0;32m
ECHO_RED = \033[0;31m
ECHO_WHITE = \033[0m

all:
	@$(CC) main.c $(CFLAGS) create
	@$(ECHO) "$(ECHO_GREEN)success.$(ECHO_WHITE)"
clean:
	@$(DEL) create*
	@$(ECHO) "$(ECHO_RED)executable file deleted.$(ECHO_WHITE)"
help_make:
	@$(ECHO) "just type: $(ECHO_GREEN)make$(ECHO_WHITE) for create executable file."
	@$(ECHO) "for delete executable file type: $(ECHO_RED)make clean$(ECHO_WHITE)"
help_create:
	@$(ECHO) "You can write only 1 or 2 args for this programm."
	@$(ECHO) "If you write only 1 args programm will create only directory with your name."
	@$(ECHO) " $(ECHO_GREEN)example:$(ECHO_WHITE) ./create dir_name"
	@$(ECHO) "If you write 2 args programm will create directory with your name and"\
	" 1 file inside this directory with your name"
	@$(ECHO) " $(ECHO_GREEN)example:$(ECHO_WHITE) ./create dir_name file_name.c"
.PHONY: all clean help_make help_create
