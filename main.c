enum	e_keys{
    DIRECTORY = 1,
    FILE_NAME
};

void    ft_action(const char *action, const char *dir, const char *file)
{
	char    *act;
    int     act_len;
    int     dir_len;
    int     file_len;

    file_len = (file ? strlen(file) + 1 : 0);
    dir_len = strlen(dir);
    act_len = strlen(action) + dir_len + file_len + 1;
    if ((act = (char *)malloc(sizeof(char) * act_len)) != NULL)
    {
        file ? snprintf(act, act_len, "%s%s/%s", action, dir, file) :
                snprintf(act, act_len, "%s%s", action, dir);
        printf("$ %s\n", act);
        if (system(act) == -1)
			printf("%s", ERR_MSG_SYS);
    } else
		if (system(ECHO_RED(ERR_MSG_MEM)) == -1)
			printf("%s", ERR_MSG_SYS);
    free(act);
}

int		ft_simple_parse(char *dir_or_file)
{
	if ((strchr(dir_or_file, '.')) == NULL)
		return (DIRECTORY);
	return (FILE_NAME);
}

int     main(int argc, char **argv)
{
	if (argc == 3)
    {
        ft_action(_MKDIR, argv[DIRECTORY], NULL);
        ft_action(_TOUCH, argv[DIRECTORY], argv[FILE_NAME]);
    } else if (argc == 2)
		if (ft_simple_parse(argv[DIRECTORY]) == DIRECTORY)
        	ft_action(_MKDIR, argv[DIRECTORY], NULL);
		else
			ft_action(_TOUCH, _CURRENT_DIR, argv[DIRECTORY]);
	else
		if (argc < 2)
		{
			if (system(ECHO_RED(ERR_MSG_LESS_ARGS)) == -1)
				printf("%s", ERR_MSG_SYS);
		} else if (argc > 3)
			if (system(ECHO_RED(ERR_MSG_2MUCH_ARGS)) == -1)
				printf("%s", ERR_MSG_SYS);
}
