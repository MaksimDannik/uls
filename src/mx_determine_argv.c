#include "uls.h"

t_li *mx_determine_argv(int argc, char *argv[], t_head *head) {
   struct stat buf;
   t_li *tmp = NULL;
    t_li *node = NULL;
    
    if (argc || argv || head)
    if (argc == head->count_flags)
        if (lstat(".", &buf) >= 0)
            mx_printstr("REALIZ FLAG D\n"); // реализовать флаг D

    
    for (; head->count_flags < argc; head->count_flags++) {
        if (lstat(argv[head->count_flags], &buf) < 0) {
            tmp = mx_create_li(argv[head->count_flags]);
            tmp->whats = 1;
            // mx_printstr(tmp->name);
            // tmp = tmp->next;

            mx_printstr("ERROR\n");
           
        }
    
       else {

            if (MX_IS_DIR(buf.st_mode)) {
                tmp = mx_create_li(argv[head->count_flags]);
                tmp->whats = 2;
                //  mx_printstr(tmp->name);
                // tmp = tmp->next;
                mx_printstr("DIR\n");
            }

    
            else {
                tmp = mx_create_li(argv[head->count_flags]);
                tmp->whats = 3;
                //mx_printstr(tmp->name);
                //tmp = tmp->next;
                mx_printstr(" File \n");
            }
        }
        if (!node) {
            node = tmp;
            mx_printstr(" ZZZZZZZZZ\n");
        }
        tmp = tmp->next;
    }
     node->next = tmp;
    // while (node) {
    //     mx_printstr(node->name);
    //     mx_printstr("\n");
    //     node = node->next;
    // }
    // system("leaks uls");
    return node;
 
 }
