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

char *gett_path(char *path, struct dirent *entry)
{
    char *str = malloc(sizeof(char) * 100);
    int i = 0;
    int j = 0;
    while (path[i] != '\0') {
        str[i] = path[i];
        i++;
    }
    str[i] = '/';
    i++;
    while (entry->d_name[j] != '\0') {
        str[i] = entry->d_name[j];
        i++;
        j++;
    }
    str[i] = '\0';
    return str;
}

int selector(int ac, char **av, struct dirent *entry, DIR *dir)
{
    char *path = av[1];
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-' && av[i][1] == 'l')
            my_ls_flag_l(entry, dir, path);
        if (av[i][0] == '-' && av[i][1] == 'a')
            my_ls_flag_a(entry, dir);
        if (av[i][0] == '-' && av[i][1] == 'd')
            my_ls_flag_d(entry, dir);
        if (av[i][0] == '-' && av[i][1] == 'R')
            my_ls_flag_r(entry, dir);
        if (av[i][0] == '-' && av[i][1] == 'r')
            my_ls_flag_r_little(entry, dir);
        if (av[i][0] == '-' && av[i][1] == 't')
            my_ls_flag_t(entry, dir);
    }
    return 0;
}
