#include "uls.h"

int main(int argc, char *argv[]) {
    t_head head;

    mx_memset(&head, 0, sizeof(t_head));
    head.flags = (int *)malloc(sizeof(int) * mx_strlen(MY_FLAGS));
   mx_memset(head.flags, 0, mx_strlen(MY_FLAGS) * sizeof(int));

//    for (int i = 0; i <= mx_strlen(MY_FLAGS); i++) {
//        head.flags[i] = 0;
//    }

    head.count_flags = head.count_flags + mx_check_flags(argc, argv, &head);
    // mx_printint(head.count_flags);



    for (int i = 0; i <= 6; i++){ // проверочка // потом удалить
        mx_printint((head.flags)[i]);
        mx_printchar('\n');
    }

return 0;


}

