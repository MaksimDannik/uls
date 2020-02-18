#include "uls.h"

static int count_inside_dir(t_lit **new_d, t_head *head) {
    int count = 0;
    t_lit *tmp = *new_d;
    DIR *dtr;
    struct dirent *ds;
                mx_printstr("START\n");

    if (MX_IS_DIR(tmp->t_st.st_mode) || MX_IS_LNK(tmp->t_st.st_mode)) {
                mx_printstr("VV\n");

        if ((dtr = opendir(tmp->fullpath)) != NULL) {
                mx_printstr("AA\n");

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
                mx_printstr("FINISH\n");

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

// for (int t = 0; new_d[t] != NULL; t++) {
//     mx_printstr(new_d[t]->name);
//     mx_printstr("\n");
//     // mx_printstr("_________________________");
// }


        for (int i = 0; new_d[i] != NULL; i++) { // open -> make array
        mx_printint(i);
                mx_printstr("\n");

            count_dir = count_inside_dir(&(new_d[i]), head); // head for check flag A
                mx_printstr("ZZZ\n");
                mx_printint(count_dir);
            if (count_dir > 0) {
                mx_printstr("1d\n");

                new_d[i]->open = malloc((count_dir + 1) * sizeof(t_lit *));
                if ((dtr = opendir(new_d[i]->fullpath)) != NULL) {
                mx_printstr("2d\n");

                    for (count_dir = 0; (ds = readdir(dtr)) != NULL ; ) {
                        if (ds->d_name[0] != '.') // need make checkA
                            new_d[i]->open[count_dir++] = createnode(ds->d_name, new_d[i]->fullpath);
                        new_d[i]->open[count_dir] = NULL;
                        mx_printstr("3");
                    }
                closedir(dtr);
                }
                mx_printstr("4d\n");

            
            // for (int i = 0; new_d[i] != NULL; i++) {
            //     for (int j = 0; new_d[i]->open[j] != NULL; j++) {
            //     mx_printstr(new_d[i]->open[j]->fullpath);
            //     mx_printstr("5d\n");
            //     //  system("leaks uls");
            //     }
            //  }
            }
            //  if (new_d[i]->error)
            //         mx_printerr(new_d[i]->error);
        }
        for (int i = 0; new_d[i] != NULL; i++) {
                for (int j = 0; new_d[i]->open[j] != NULL; j++) {
                mx_printstr(new_d[i]->open[j]->fullpath);
                mx_printstr("5d\n");
                //  system("leaks uls");
                }
             }
        
}


