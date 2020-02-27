#include "uls.h"

void mx_print(t_lit *name, t_sz *size, t_head *head) {
    time_t *chtime = &name->t_st.st_ctime;
    time_t *atime = &name->t_st.st_atime;
    time_t *t = &name->t_st.st_mtime;

    mx_print_per(name);
    mx_print_lnk(name, size);
    if ((((head->flags[mx_get_char_index(MY_FLAGS, 'l')] == 1)) &&
        ((head->flags[mx_get_char_index(MY_FLAGS, 'g')] == 0))) ||
        (((head->flags[mx_get_char_index(MY_FLAGS, 'o')] == 1)) &&
        ((head->flags[mx_get_char_index(MY_FLAGS, 'g')] == 0))))
        mx_get_user_name(name, size->usr);
    if ((((head->flags[mx_get_char_index(MY_FLAGS, 'l')] == 1)) &&
        ((head->flags[mx_get_char_index(MY_FLAGS, 'o')] == 0))) ||
        (((head->flags[mx_get_char_index(MY_FLAGS, 'g')] == 1)) &&
        ((head->flags[mx_get_char_index(MY_FLAGS, 'o')] == 0))))
        mx_get_group_name(name, size->group);
    mx_print_sz(name, size);
    if (head->flags[mx_get_char_index(MY_FLAGS, 'u')] == 1)
        t = atime;
    if (head->flags[mx_get_char_index(MY_FLAGS, 'c')] == 1)
        t = chtime;
    mx_edit_time(name, ctime(t), head);
     // print link_and_color
    mx_printchar('\n');
}
