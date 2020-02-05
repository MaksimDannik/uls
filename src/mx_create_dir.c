 #include "uls.h"

t_dir *mx_create_dir(char *name) { //, char *path) {
    t_dir *tmp = (t_dir *)malloc(sizeof(t_dir));

    tmp->name = name;
    //tmp->path = path;
    tmp->next = NULL;
    return tmp;
}


t_file *mx_create_file(char *name) {
    t_file *tmp = (t_file *)malloc(sizeof(t_file));

    tmp->name = name;
    tmp->next = NULL;
    return tmp;
}
