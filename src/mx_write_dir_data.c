#include "uls.h"

static char *make_full_path(char *dirname, char *filename) {
    char *full_path = NULL;

    if (mx_strcmp(dirname, "/")) {
        full_path = mx_strnew(mx_strlen(filename) + 1);
        mx_strcat(full_path, dirname);
        mx_strcat(full_path, filename);
    }
    else {
        full_path = mx_strnew(mx_strlen(dirname) + mx_strlen(filename) + 1);
        mx_strcat(full_path, dirname);
        mx_strcat(full_path, "/");
        mx_strcat(full_path, filename);
    }
    return full_path;
}

void mx_write_dir_data(char *file, t_head *head, DIR *dir) { // dir_data
    t_dir *tmp = mx_create_dir(file);
    struct dirent *dirent;
    struct stat new_st;
     char *tmp_one = NULL;
    // char *tmp_two = NULL;

    head->dir = tmp;
    lstat(file, &tmp->st);

    while ((dirent = readdir(dir)) != NULL) {
        tmp_one = make_full_path(dirent->d_name, file);
        // if (mx_strcmp(file, "/")) {
        //     mx_printchar('\n');
        //     tmp_one = mx_strjoin(file, "/");
        //     tmp_two = mx_strjoin(tmp_one, dirent->d_name);
        //     mx_strdel(&tmp_one);
        //     mx_printstr(tmp_two);
// cоздать что-то куда будем записивать тмп_ту
            //mx_strdel(&tmp_two); //нужно сделать стат переменную, занести в нее тмп_ту и зафришить
        //}
       // else {
           // tmp_two = file;
            // mx_printstr("HERE1111");
             mx_printchar('\n');
       // }
        lstat(tmp_one, &new_st);
        if (MX_IS_DIR(new_st.st_mode)) {
            mx_printstr(tmp_one);
            mx_write_dir_data(tmp_one, head, dir);//делаем рекурсию (пока @тмп_ту@ ---> потом ее уберем)
      //  else 
       // dirent->d_name;// вместо файл 
        // я должен проверить lstat папка или файл// 
        }
    }

}
