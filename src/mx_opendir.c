#include "uls.h"

void mx_del(t_lit ***args) {
    t_lit **kill_arr = *args;

    for (int i = 0; kill_arr[i] != NULL; i++) {
        mx_strdel(&kill_arr[i]->name);
        mx_strdel(&kill_arr[i]->fullpath);
        if (kill_arr[i]->error != NULL)
            mx_strdel(&kill_arr[i]->error);
            free(kill_arr[i]);
            kill_arr[i] = NULL;
        }
        free(*args);
        *args = NULL;
}

static int count_inside_dir(t_lit **new_d) {
    int count = 0;
    t_lit *tmp = *new_d;
    DIR *dtr;
    struct dirent *ds;

    if (tmp && *new_d) {
        (*new_d)->error = NULL;
        lstat(tmp->fullpath, &(tmp->t_st));
        if (MX_IS_DIR(tmp->t_st.st_mode) || MX_IS_LNK(tmp->t_st.st_mode)) {
            if ((dtr = opendir(tmp->fullpath)) != NULL) {
                while ((ds = readdir(dtr)) != NULL)
                    if (ds->d_name[0] != '.') {
                        count++;
                    }
                    closedir(dtr);
            }
            else {
                (*new_d)->error = mx_strdup(strerror(errno));
                return -1;
            }
        }
    }
    return count;
}

static t_lit *createnode(char *name, char *path) {
    t_lit *node = (t_lit *)malloc(1 * sizeof(t_lit));

    node->name = mx_strdup(name);
    node->fullpath = mx_strdup(path);
    mx_join(&node->fullpath, "/");
    mx_join(&node->fullpath, name);
    node->error = NULL;
    if (lstat(node->fullpath, &(node->t_st)) == -1)
        node->error = mx_strdup(strerror(errno));
    node->open = NULL;
    return node;
}

void mx_opendir(t_lit **new_d, t_head *head) {
    DIR *dtr;
    struct dirent *ds;
    int count_dir = 0;

    for (int i = 0; new_d[i] != NULL; i++) { // open -> make array
        if (new_d[i] != 0) {
            count_dir = count_inside_dir(&(new_d[i])); // head for check flag A);
            if (count_dir > 0) {
                new_d[i]->open = malloc((count_dir + 1) * sizeof(t_lit *));
                if ((dtr = opendir(new_d[i]->fullpath)) != NULL) {
                    for (count_dir = 0; (ds = readdir(dtr)) != NULL ; ) {
                        if (ds->d_name[0] != '.')
                            new_d[i]->open[count_dir++] = createnode(ds->d_name, new_d[i]->fullpath);
                        new_d[i]->open[count_dir] = NULL;
                    }
                closedir(dtr);
                }
            }
        }
    }
    mx_output(new_d, head); // head for check flags/  new /// Бодя коментируй чтобы скомпилить

    // out_put (new_d)//
    // printdirname()//
    // outputmenu(open)//
    if (head) {

    }
    // if R -> opendir (delfiles(open))
        // int x = 0;
    // int r = 1;

    // for (int x = 0; new_d[x] != NULL; x++) {
    //     // if (head->output == 1) {
    //     //     mx_printstr(new_d[x]->fullpath);
    //     //     mx_printstr(":\n");
    //     // }
    //     if (new_d[x]->error) {
    //         mx_printerr("uls: ");
    //         char *str = mx_memrchr(new_d[x]->name, '/', mx_strlen(new_d[x]->name));
    //         mx_printerr(str + 1);
    //         mx_printerr(": ");
    //         mx_printerr(new_d[x]->error);
    //         mx_printerr("\n");
    //     }
    //     if (new_d[x]->open != NULL) { // for output files
    //         for (int j = 0; new_d[x]->open[j] != NULL; j++) {
    //             mx_printstr(new_d[x]->open[j]->name);
    //             mx_printstr("\n");
    //         }
    //         mx_printstr("\n");
    //         if (r) {
    //             head->output = 1;
    //                 mx_del_fils(&new_d[x]->open, head);
    //                 if (new_d[x]->open != NULL)
    //                     mx_opendir(new_d[x]->open, head);
    //             }
    //     }
    // }
}

