int		main(int argc, string *argv)
{
	STOP_IF(argc < 2, return (-1), ERR_NOARGS);
	if (argv[1][0] != '-')
		ft_noflags_parse(argc, argv);
	else
		ft_flags_parse(argv);
}
