#include "uls.h"

//void func(t_st buf);
// struct dirent *entry;


void mx_check_mode(char **file, int argc, t_head *head) { //file or dir
   // t_st buf;
    DIR *dir;
    int end_flg = 1;
                             // struct dirent *entry;
    for (int i = 1; i < argc; i++) {

        dir = opendir(file[i]);
        if (file[i][0] == '-' && file[i][1] == '-')
            end_flg = 0;
        else if (file[i][0] == '-' && end_flg && mx_check_flag(&file[i][1]))
            mx_printstr("FLAG"); 
        // else if (lstat(file[i], &buf) < 0) {
        //     mx_printerr("uls: ");
        //  perror(file[i]); ///занести в структуру мистейк
        // }
        // else if (dir == 0)
        //      perror(file[i]); // work, but herovo!!!! konsol --------->|!./uls /Users/neo!|  (uls: /uls: Permission denied)  (ls: neo: Permission denied)
        else if (dir) {
            mx_printstr("DIR");//потім видалити
            mx_write_dir_data(file[i], head, dir);
            end_flg = 0; 
        }
        else if (!dir) { // записую сюди файли та !!!!!!!!!!!!!ерор назву файлу
            mx_printstr("file");
            end_flg = 0; 
        }
        mx_printchar('\n');///delated in future
    dir ? closedir(dir) : 0;
    }
}
// крч файли директорії та ерор папки виявили
// тепер треба їх записати в одну структуру
// просортувати компеіром
