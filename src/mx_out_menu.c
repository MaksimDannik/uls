#include "uls.h"

void mx_out_menu(t_lit ***name, t_head *head, int fg) {
    if (**name != NULL) {
        //mx_sort
        if (head->flags[mx_get_char_index(MY_FLAGS, 'l')] == 1) {
            mx_long_out(*name, head, fg);
        }
    }
}
