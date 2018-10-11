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
