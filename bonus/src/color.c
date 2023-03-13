/*
** EPITECH PROJECT, 2022
** ls
** File description:
** psu
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include "my.h"
#include "proto.h"

void flag_l_color(struct dirent *entry, DIR *dir, struct stat sb)
{
    if (S_ISDIR(sb.st_mode))
        my_putstr("\033[1;34m");
    if (S_ISREG(sb.st_mode))
        my_putstr("\033[0m");
    if (!S_ISDIR(sb.st_mode) && (sb.st_mode & S_IXUSR))
        my_putstr("\033[1;32m");
    if (S_ISLNK(sb.st_mode))
        my_putstr("\033[1;35m");
    if (S_ISCHR(sb.st_mode))
        my_putstr("\033[1;33m");
    if (S_ISBLK(sb.st_mode))
        my_putstr("\033[1;33m");
    if (S_ISFIFO(sb.st_mode))
        my_putstr("\033[1;33m");
    if (S_ISSOCK(sb.st_mode))
        my_putstr("\033[1;33m");
    my_putstr(entry->d_name);
    my_putstr("\033[0m");
}
