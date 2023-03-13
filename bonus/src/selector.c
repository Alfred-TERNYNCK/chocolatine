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

int selector(int ac, char **av, struct dirent *entry, DIR *dir)
{
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-' && av[i][1] == 'l')
            my_ls_flag_l(entry, dir);
        if (av[i][0] == '-' && av[i][1] == 'a')
            my_ls_flag_a(entry, dir);
        if (av[i][0] == '-' && av[i][1] == 'd')
            my_ls_flag_d(entry, dir);
        if (av[i][0] == '-' && av[i][1] == 'R')
            my_ls_flag_r(entry, dir);
        if (av[i][0] == '-' && av[i][1] == 't')
            my_ls_flag_t(entry, dir);
    }
    return 0;
}
