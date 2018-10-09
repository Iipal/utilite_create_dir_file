void	ft_flags_action(string *argv, char act)
{
	if (act == 'd')
		if (g_is_d == 0)
		{
			g_is_d = 1;
			STOP_IF(argv[2] == NULL, return, ERR_DFLAG);
			ft_action(_SYS_MKDIR, argv[2], NULL);
		}
	if (act == 'f')
		if (g_is_f == 0)
		{
			g_is_f = 1;
			STOP_IF(argv[2] == NULL, return, ERR_FFLAG);
			g_is_d == 1 ?
				(argv[3] != NULL ? ft_action(_SYS_TOUCH, argv[2], argv[3]) :
				 	printf("%s", ERR_FFLAG_AFTER_D))
				: ft_action(_SYS_TOUCH, ".", argv[2]);
		}
}

void	ft_flags_parse(string *flags)
{
	string	sequence;
	int		is_flags;

	g_is_d = 0;
	g_is_f = 0;
	is_flags = 0;
	STOP_IF(FLAGS_MAX + 1 < strlen(flags[1]),
			return , ERR_TOOMANY_FLAGS);
	STOP_IF((sequence = strpbrk(flags[1], FLAGS)) == NULL,
			return, ERR_UNKNOW_FLAGS);
	STOP_IF(FLAGS_MAX == strlen(flags[1]),
			ft_flags_action(flags, flags[1][1]); return, "%s", "");
	is_flags = 1;
	while(sequence != NULL)
	{
		ft_flags_action(flags, sequence[0]);
		if (is_flags >= FLAGS_MAX)
			break;
		STOP_IF(((sequence = strpbrk(sequence + 1, FLAGS)) == NULL),
				return, ERR_UNKNOW_FLAGS);
		is_flags++;
	}
}
