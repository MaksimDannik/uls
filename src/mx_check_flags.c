#include "uls.h"

static void illegal_option(char c) {
    
    mx_printerr("uls: illegal option -- ");
    write(2, &c, 1);
    mx_printerr("\nusage: uls [-");
    mx_printerr(MY_FLAGS);
    mx_printerr("] [file ...]\n");
    exit(1);
}

int mx_check_flags(int argc, char *argv[], t_head *head) {
    int res = 1;
    int h = 0;

    for (int i = 1; i < argc && argv[i][0] == '-'; i++) {
        if (argv[i][0] == '-' && !argv[i][1])
            return res;
        if (mx_strcmp(argv[i], "--") == 0)
            return res + 1;
        if (argv[i][0] == '-') {
            res ++;
            for (int j = 1; argv[i][j]; j++) {
                if (mx_get_char_index(MY_FLAGS, (argv[i][j])) == -1)
                    illegal_option(argv[i][j]);
                h = mx_get_char_index(MY_FLAGS, argv[i][j]);
                if (h >= 0)
                    head->flags[h] = 1;
            }
        }// когда залетает просто -, нужно написать ошибку
    }
    return res;
}
