void	ft_action(const string action, const string dir, const string file)
{
	string	act;
	int		act_len;
	int		dir_len;
	int		file_len;

	file_len = (file ? (strlen(file) + 1) : 0);
	dir_len = strlen(dir);
	act_len = strlen(action) + dir_len + file_len + 1;
	STOP_IF((act = (string)malloc(sizeof(char) * act_len)) == NULL,
			return , ERR_NOMEMORY);
	file ? snprintf(act, act_len, "%s%s/%s", action, dir, file) :
		snprintf(act, act_len, "%s%s", action, dir);
	printf("$ %s\n", act);
	system(act);
	free(act);
}

void	ft_noflags_parse(int argc, string *argv)
{
	if (argc == 3)
	{
		ft_action(_SYS_MKDIR, argv[1], NULL);
		ft_action(_SYS_TOUCH, argv[1], argv[2]);
	} else if (argc == 2)
	{
		if (strchr(argv[1], '.') == NULL)
			ft_action(_SYS_MKDIR, argv[1], NULL);
		else
			ft_action(_SYS_TOUCH, ".", argv[1]);
	} else
		STOP_IF(argc > 3, return , ERR_TOOMANY_ARGS_NOFLAGS);
}
