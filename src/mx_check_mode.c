#include "uls.h"



//void func(t_st buf);

void mx_check_mode(char *file) { //file or dir
    t_st buf;
    DIR *dir = opendir(file);;
    // struct dirent *entry;


   // lstat(file, &buf);
    if (file[0] == '-' && mx_check_flag(&file[1])) 
        mx_printstr("FLAG"); 
    else if (lstat(file, &buf) < 0)
        perror(file);
    else if (dir || !dir)
        mx_printstr("DIR or file");
    mx_printstr("\n");
    dir ? closedir(dir) : 0;

}

