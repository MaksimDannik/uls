#include "uls.h"

//void func(t_st buf);
// struct dirent *entry;


void mx_check_mode(char **file, int argc) { //file or dir
    t_st buf;
    DIR *dir;
    int end_flg = 1;
                             // struct dirent *entry;
    for (int i = 1; i < argc; i++) {
        dir = opendir(file[i]);
        if (file[i][0] == '-' && file[i][1] == '-')
            end_flg = 0;
        else if (file[i][0] == '-' && end_flg && mx_check_flag(&file[i][1]))
            mx_printstr("FLAG"); 
        else if (lstat(file[i], &buf) < 0) {
            mx_printerr("uls: ");
            perror(file[i]);
        }
        else if (dir == 0)
             perror(file[i]); // work, but herovo!!!! konsol --------->|!./uls /Users/neo!|  (uls: /uls: Permission denied)  (ls: neo: Permission denied)
        else if (dir || !dir) {
            mx_printstr("DIR or file");
            end_flg = 0;
        }
        mx_printchar('\n');///delated in future
    dir ? closedir(dir) : 0;
    }
}
