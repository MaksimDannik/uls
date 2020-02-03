 #include "uls.h"

t_dir *mx_create_dir(char *name) { //, char *path) {
    t_dir *tmp = (t_dir *)malloc(sizeof(t_dir));

    tmp->name = name;
    //tmp->path = path;
    tmp->next = NULL;
    return tmp;
}
