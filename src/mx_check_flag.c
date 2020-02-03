#include "uls.h"


static void error_flag(char *file, int i) {
    char *tmp = mx_strndup(&file[i], 1);

        mx_printerr("uls: illegal option -- ");
        mx_printerr(tmp);
        mx_printchar('\n');
        mx_printerr("usage: uls [-LARarls] [file ...]");
        mx_strdel(&tmp);
        mx_printchar('\n');
        exit(1);
}
// проверяет если ли коректные флаги. если нет, ошибка.// если есть, создаем масив флагов
int mx_check_flag(char *file) {
    int invalid = 0;
    int i = 0;

    while (file[i]) {
        invalid = 1;
        for (int j = 0; MY_FLAGS[j]; j++) 
            if (file[i] == MY_FLAGS[j]) // if we have same flag 
                invalid = 0;
        if (invalid)
            error_flag(file, i);
        i++;
    }
    return i;
}
