#include "uls.h"

// void mx_free_li(t_li *li) {
//     mx_strdel(&li->fullpath);
//     mx_strdel(&li->name);
//     free(li);
  
// }

void mx_push_fr(t_li **li, t_li *tmp) {///
    
    
    
    t_li *nd = *li;
    if (!tmp)
        return;
    else if (nd == NULL)
        *li = tmp;
    else if (nd) {
        tmp->next = *li;
        *li = tmp;
    } 
}


t_li *mx_determine_argv(int argc, char *argv[], t_head *head) {
    struct stat buf;
    t_li *tmp = NULL;
    t_li *node = NULL;

    if (argc == head->count_flags)
        if (lstat(".", &buf) >= 0)
            mx_printstr("REALIZ FLAG D\n"); // реализовать флаг D

    
    for (; head->count_flags < argc; head->count_flags++) {
       if (lstat(argv[head->count_flags], &buf) < 0) {
            tmp = mx_create_li(argv[head->count_flags]);
            tmp->whats = 1;
            mx_push_fr(&node, tmp);
            mx_printstr("ERROR\n");
           
        }
        else {
             if (MX_IS_DIR(buf.st_mode)) {
                 tmp = mx_create_li(argv[head->count_flags]);
                 tmp->whats = 2;
                 mx_push_fr(&node, tmp);
                 mx_printstr("DIR\n");
             }

    
             else {
                 tmp = mx_create_li(argv[head->count_flags]);
                 tmp->whats = 3;
                 mx_push_fr(&node, tmp);
                 mx_printstr(" File \n");
             }
         }
        
    }
    return node;
 }
