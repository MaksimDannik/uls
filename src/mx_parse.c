#include "uls.h"

static int countread(t_lit **arg, t_head *head) {
    int count = 0;
    t_lit *args = *arg;
    DIR *dir;
    struct dirent *ds;

    if (MX_IS_DIR(args->t_st.st_mode)) {
        if ((dir = opendir(args->name)) != NULL) {
            while ((ds = readdir(dir)) != NULL)
                count++;
            closedir(dir);
        }
        else {
            (*arg)->error = mx_strdup(strerror(errno));
            return -1;
        }
    }
    return count;
}

void mx_opendir(t_lit ***args, t_head *head) {
    //DIR *dir;
   // struct dirent *dd;
    int count = 0;

if (head) {


}
    for (int i = 0; (*args)[i] != NULL; i++) {
        count = countread(&(*args)[i], head);
    }

}


void mx_parse(int argc, char **argv, t_head *head) {
    int count = head->count_flags;
    t_lit **args = mx_getname(argc, argv, count);


if (head) {
    
}
    if (args)
        mx_opendir(&args, head);
    
    // for (int i = 0; args[i] != NULL; i++) { // check **args // i need make sort after make this functions.
    //     // mx_printerr("ls: ");
    //     mx_printerr(args[i]->name);
    // mx_printerr("s: ");
    // mx_printerr(args[i]->error);
    // }


    return;
}

