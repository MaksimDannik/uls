#include "uls.h"

int main(int argc, char *argv[]) {
 
    t_head head;
    t_li *list = NULL;
    t_li *tmp = NULL;


    mx_memset(&head, 0, sizeof(t_head)); // зануляем структуру head
    head.flags = (int *)malloc(sizeof(int) * mx_strlen(MY_FLAGS)); // присваиваем  память масиву int 
    mx_memset(head.flags, 0, mx_strlen(MY_FLAGS) * sizeof(int)); // зануляем масив на наше количество флагов
    head.count_flags = head.count_flags + mx_check_flags(argc, argv, &head); //заполнили масив флагов(0001001), и подсчитали где заканчиваются флаги 
   list = mx_determine_argv(argc, argv, &head);
    tmp = list;

     if (!tmp) {
     mx_printstr("NEMA\n");
    }
    while (tmp) {
        mx_printstr(tmp->name);
        mx_printstr("\n");
        tmp = tmp->next;
    }

    


    // mx_printstr(head->data);


    // for (int i = 0; i <= 6; i++){ // проверочка // потом удалить
    //     mx_printint((head.flags)[i]);
    //     mx_printchar('\n');
    // }
 system("leaks uls");

return 0;


}

