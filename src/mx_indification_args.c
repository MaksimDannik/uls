#include "uls.h"

static void add_in_new_array(t_lit **args, t_lit **new_args) {
    int count_new_arg = 0;
    t_lit **tmp = (t_lit **)malloc(sizeof(t_lit *));
    tmp = args;

    for (int i = 0; args[i] != NULL; i++) {
        if (args[i]->what_is_it == 1) {
            new_args[count_new_arg] = (t_lit *)malloc(sizeof(t_lit));
            new_args[count_new_arg]->name = mx_strdup(tmp[i]->name);
            new_args[count_new_arg]->fullpath = mx_strdup(tmp[i]->fullpath);
            count_new_arg++;
            mx_printstr(tmp[i]->name);
            mx_printstr("\n");
        }
    }
     new_args[count_new_arg] = NULL;
     mx_del_list(tmp);
     free(tmp);
}

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
                // mx_printstr("FILE \n"); //delate
            }
        }
        dir ? closedir(dir) : 0;
    }
    // free(arg[i]); // after thit not leaks. Before HAVE LEAKS
    mx_printint(sum_file);// delate
    return sum_file;
}

void mx_indification_args(t_lit **args, t_head *head) {
    // if (head->count_flags == 1) {    --------------------> after variable (переменная)
    //     //print_multi_colon // Bodya create this function
    //     return;
    // }
    head->sum_file = check_file(&args);
    t_lit **new_ar = (t_lit **)malloc((head->sum_file + 1) * sizeof(t_lit *)); // i need free new_ar[full] == NULL/
    add_in_new_array(args, new_ar);//



// system("leaks uls");//


if (head || head->sum_file) {

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
