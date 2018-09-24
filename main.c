/** \page mainpage IMPORTANT!!!
 * Without any include's because i use flags -include when compile.*/
/** \page echo_red Used only 1 macros for show ERROR message's.*/
#define ECHO_RED(msg) "echo \"\033[0;31m" msg "\033[0m\""
/** \page enum Just simple enum for argv*/
enum    e_keys {
    DIRECTORY = 1,
    FILE_NAME
};
/** \page ft_action 1 and important function what can do all what we want:
 *  \c act Its wille be string where we will storage our command for function system().
 *  \c act_len Summary length for allocate memory for our string.
 *  \c dir_len and \c file_len just to not use twice strlen().
 *  \с file_len will initialized by something only if we have something in our *file string.
 *  Simple if to check if we have enought memory for allocate our string.i:
 *  Ternary operator again, for the same like when we initiliazied \c file_len.*/
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
    free(act);
}
/** \page main Just main.*/
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
