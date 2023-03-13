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
    my_putstr(entry->d_name);
}
