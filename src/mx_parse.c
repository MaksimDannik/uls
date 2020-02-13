#include "uls.h"

// static t_lit**


// static void print_err(t_lit **arg) {
//     for (int i = 0; arg[i] != NULL; i++) {
//         if (arg[i]->error) {
//             mx_printerr("ls: ");
//             mx_printerr(arg[i]->name);
//             mx_printerr(": ");
//             mx_printerr(arg[i]->error);
//             mx_printerr("\n");
//         }
//     }
// }

void mx_parse(int argc, char **argv, t_head *head) {
    int count = head->count_flags;
    t_lit **args = mx_getname(argc, argv, count);
    free(args);
if (args) {

}
  //  mx_sort_asci(&args);
    //print_err(args);
    // args = del_invalid_argv(args);

    
    // for (int i = 0; args[i] != NULL; i++) { // check **args // i need make sort after make this functions.
    //     // mx_printerr("ls: ");
    //     mx_printerr(args[i]->name);
    //     mx_printerr("\n");
    // }
    return;
}
