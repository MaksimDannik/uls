#include "uls.h"

t_data *mx_create_struct(char *name) {
    t_data *tmp = (t_data *)malloc(sizeof(t_data));
    tmp->name = NULL;

    tmp->name = name;
    tmp->next = NULL;
    return tmp;
}
