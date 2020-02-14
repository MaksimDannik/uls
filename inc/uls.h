#ifndef PATH_H
#define PATH_H

#include <string.h>
#include <errno.h>
#include "libmx/inc/libmx.h"
#include "sys/stat.h"
#include <sys/types.h>//opendir
#include <dirent.h> // opendir readdir
#include <limits.h> // limits PATH_MAX

#define MX_IS_BLK(mode) (((mode) & S_IFMT) == S_IFBLK)
#define MX_IS_CHR(mode) (((mode) & S_IFMT) == S_IFCHR)
#define MX_IS_DIR(mode) (((mode) & S_IFMT) == S_IFDIR)
#define MX_IS_LNK(mode) (((mode) & S_IFMT) == S_IFLNK)
#define MX_IS_SOCK(mode) (((mode) & S_IFMT) == S_IFSOCK)
#define MX_IS_FIFO(mode) (((mode) & S_IFMT) == S_IFIFO)
#define MX_IS_WHT(mode) (((mode) & S_IFMT) == S_IFWHT)
#define MX_IS_REG(mode) (((mode) & S_IFMT) == S_IFREG)

#define MY_FLAGS "LARarls" //our flags

//typedef struct stat t_st;

typedef struct s_lit {
    char *name;
    char *fullpath;
    char *error;// write mistake errno
    struct stat t_st;
    struct s_lit **open;
} t_lit;
 
 typedef struct s_head {
    int *flags;
    int count_flags;

 } t_head;


int mx_check_flags(int argc, char *argv[], t_head *head);
t_lit **mx_getname(int argc, char **argv, int i);
void mx_parse(int argc, char **argv, t_head *head);
void mx_sort_asci(t_lit ***arg);
t_lit **mx_make_new_list(t_lit **args, int valid_node);
void mx_del_list(t_lit **args);
#endif


