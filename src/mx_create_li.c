#include "uls.h"

t_li *mx_create_li(char *name) {
    t_li *tmp = (t_li *)malloc(sizeof(t_li));

    tmp->name = name;
    tmp->next = NULL;

    return tmp;
}
