/*
** EPITECH PROJECT, 2022
** ls
** File description:
** psu
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "proto.h"

int my_ls(struct dirent *entry, DIR *dir)
{
    int i = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.' && entry->d_name[0] != '\0') {
            my_putstr(entry->d_name);
            my_putchar('\n');
        }
    }
    return 0;
}

int main (int ac, char **av)
{
    DIR *dir = opendir("./");
    if (dir == NULL)
        return 84;
    struct dirent *entry = readdir(dir);
    if (entry == NULL)
        return 84;
    if (ac == 1)
        my_ls(entry, dir);
    selector(ac, av, entry, dir);
    closedir(dir);
    return 0;
}
