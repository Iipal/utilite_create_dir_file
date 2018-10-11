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
