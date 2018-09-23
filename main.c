#define ECHO_RED(msg) "echo \"\033[0;31m" msg "\033[0m\""

enum    e_keys {
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
        system(act);
    } else
        system(ECHO_RED("mem err."));
}

int     main(int argc, char **argv)
{
    if (argc == 3)
    {
        ft_action("mkdir ", argv[DIRECTORY], NULL);
        ft_action("touch ", argv[DIRECTORY], argv[FILE_NAME]);
    } else if (argc == 2)
        ft_action("mkdir ", argv[DIRECTORY], NULL);
    else
        system(ECHO_RED("not enought args."));
}
