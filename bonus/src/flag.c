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
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include "my.h"
#include "proto.h"

int my_ls_flag_t(struct dirent *entry, DIR *dir)
{
    struct stat sb;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.' && entry->d_name[0] != '\0') {
            stat(entry->d_name, &sb);
            my_putstr(entry->d_name);
            my_putchar('\n');
        }
    }
    return 0;
}

int my_ls_flag_r(struct dirent *entry, DIR *dir)
{
    struct stat sb;
    return 0;
}

int my_ls_flag_d(struct dirent *entry, DIR *dir)
{
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.' && entry->d_name[0] != '\0') {
            my_putstr(entry->d_name);
            my_putchar('\n');
        }
    }
    return 0;
}

int my_ls_flag_a(struct dirent *entry, DIR *dir)
{
    if ((dir = opendir("./")) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            my_putstr(entry->d_name);
            my_putchar('\n');
        }
        closedir(dir);
    } else {
        perror("");
        return EXIT_FAILURE;
    }
    return 0;
}
