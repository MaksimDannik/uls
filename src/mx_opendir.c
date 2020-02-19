#include "uls.h"

static int count_inside_dir(t_lit **new_d, t_head *head) {
    int count = 0;
    t_lit *tmp = *new_d;
    DIR *dtr;
    struct dirent *ds;

    lstat(tmp->fullpath, &(tmp->t_st));
    if (MX_IS_DIR(tmp->t_st.st_mode) || MX_IS_LNK(tmp->t_st.st_mode)) {
        if ((dtr = opendir(tmp->fullpath)) != NULL) {
            while ((ds = readdir(dtr)) != NULL)
                if (ds->d_name[0] != '.') // need make checkA
                    count++;
                closedir(dtr);
        }
        else {
            (*new_d)->error = mx_strdup(strerror(errno));
            return -1;
        }
    }
    return count;
    if (head) {

    }
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

    if (!new_d)
        return;

        for (int i = 0; new_d[i] != NULL; i++) { // open -> make array
            count_dir = count_inside_dir(&(new_d[i]), head); // head for check flag A
                    // mx_printstr("Start\n");
            if (count_dir > 0) {
                new_d[i]->open = malloc((count_dir + 1) * sizeof(t_lit *));
                if ((dtr = opendir(new_d[i]->fullpath)) != NULL) {
                    // mx_printstr("inside\n");
                    for (count_dir = 0; (ds = readdir(dtr)) != NULL ; ) {
                    // mx_printstr("read\n");
                        if (ds->d_name[0] != '.') // need make checkA
                            new_d[i]->open[count_dir++] = createnode(ds->d_name, new_d[i]->fullpath);
                        new_d[i]->open[count_dir] = NULL;
                    }
                    // mx_printstr("outside\n");
                closedir(dtr);
                }
            }

        }
                //     mx_printstr("FINISH\n");
                // if (new_d[0]->open != NULL) {
                //     printf("%s\n", new_d[0]->open[0]->name);
        // int R = 1;
        // if (R) {
        //     for (int v = 0; new_d[v] != NULL; v++) {
        //             mx_printstr("вошел\n");
        //         for (int g = 0; new_d[v]->open[g] != NULL; g++) {
                    
        //             mx_printstr("num 1\n");
        //             if (MX_IS_DIR(new_d[v]->open[g]->t_st.st_mode) || MX_IS_LNK(new_d[v]->open[g]->t_st.st_mode)) {
        //             mx_printstr("num 2\n");

        //                 mx_opendir(&new_d[v]->open[g], head);
        //             }
        //             mx_printstr("num 3\n");

        //         }
        // }
        // }
// }
        for (int i = 0; new_d[i] != NULL; i++) {
                for (int j = 0; new_d[i]->open[j] != NULL; j++) {
                mx_printstr(new_d[i]->open[j]->fullpath);
                mx_printstr("\n");
                }
             }
}


