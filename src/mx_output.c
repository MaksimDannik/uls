#include "uls.h"

void mx_output(t_lit **new_d, t_head *head) {
    if (new_d) {
        for (int i = 0; new_d[i] != NULL; i++) {
            if (head->output == 1) {
                if (new_d[i]->fullpath[0] == '/' && new_d[i]->fullpath[1] == '/')
                    mx_printstr(&new_d[i]->fullpath[1]);
                else
                    mx_printstr(new_d[i]->fullpath);
                mx_printchar(':');
                mx_printchar('\n');
            }

    }
}
}
