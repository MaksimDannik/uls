#include "uls.h"

static int check_file(t_lit ***args) { // whith *

    int sum_file = 0;
    t_lit **arg = *args;
    struct stat *buf = NULL;
    DIR *dir;

    for (int i = 0; arg[i] != NULL; i++) { // int i = 0;
        dir = opendir(arg[i]->name);
        if (!dir) {
            if (errno == 13) {
            }
            else if (lstat(arg[i]->name, buf)) { // check File or no 
                arg[i]->what_is_it = 1;
                sum_file++;
                //mx_printstr("FILE \n"); delate
            }
        }
        dir ? closedir(dir) : 0;
    }
    // free(arg[i]); // after thit not leaks. Before HAVE LEAKS
    mx_printint(sum_file);// delate
    return sum_file;
}

void mx_indification_args(t_lit **args, t_head *head) {
    // if (head->count_flags == 1) {
    //     //print_multi_colon // Bodya create this function
    //     return;
    // }
    int sum_file = check_file(&args);
system("leaks uls");////////// // ИСКАЛ ЛИКИ, НАШЕЛ


if (head || sum_file) {

}
// struct stat *buf = NULL;
// DIR *dir;
//  for (int i = 0; args[i] != NULL; i++) {
//     dir = opendir(args[i]->name);

//     if (dir) {
//             mx_printstr("DIR");
//     }
//     else if (!dir) {
//         if (errno == 13)
//             perror(args[i]->name);
//         else if (lstat(args[i]->name, buf))
//             mx_printstr("FILE");
        

//     }
 }
