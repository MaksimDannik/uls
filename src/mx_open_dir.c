#include "uls.h"
/*
void list_dir(const char *dir_name) { // рекурсивный вывод
    DIR *d = opendir(dir_name);
    struct dirent *entry = NULL;
    const char *d_name;

    if (!d) 
        return;
    while ((entry = readdir(d)) != NULL) {
        d_name = entry->d_name;
        mx_printstr(dir_name);//print the name of the file and directory
        mx_printchar('/');
        mx_printstr(d_name);
        mx_printchar('\n');

    }
}*/
