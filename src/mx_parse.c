#include "uls.h"

static sizearr(t_lit **arg) {
    int i = 0;
    
    while (arg[i])
        i++;
    return i;
}

static void mx_sort_asci(t_lit ***arg) {
    t_lit **args = *arg;
    int size = sizearr(args);

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            
        }
    }
}

static void print_err(t_lit **arg) {
    for (int i = 0; arg[i] != NULL; i++) {
        if (arg[i]->error) {
            mx_printerr("ls: ");
            mx_printerr(arg[i]->name);
            mx_printerr(": ");
            mx_printerr(arg[i]->error);
            mx_printerr("\n");
        }
    }
}

void mx_parse(int argc, char **argv, t_head *head) {
    int count = head->count_flags;
    t_lit **args = mx_getname(argc, argv, count);

    mx_sort_asci(&args);//  допилить
    print_err(args);
 
    

    // for (int i = 0; args[i] != NULL; i++) { // check **args // i need make sort after make this functions.
    //     // mx_printerr("ls: ");
    //     mx_printerr(args[i]->name);
    // }
    return;
}


