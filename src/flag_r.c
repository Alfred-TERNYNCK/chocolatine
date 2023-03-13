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

char *get_path(char *path, char *name)
{
    char *new_path = malloc(sizeof(char) *
    (my_strlen(path) + my_strlen(name) + 2));
    int i = 0;
    int j = 0;

    for (; path[i] != '\0'; i++)
        new_path[i] = path[i];
    if (path[i - 1] != '/')
        new_path[i++] = '/';
    for (; name[j] != '\0'; j++)
        new_path[i + j] = name[j];
    new_path[i + j] = '\0';
    return new_path;
}

void display_path(char *path)
{
    path = get_path(path, ".");
    my_putstr("./");
    write(1, path, my_strlen(path) - 2);
    my_putstr(":\n");
}

void print_inside_dir(DIR *dir)
{
    struct dirent *entry = readdir(dir);
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.' && entry->d_name[0] != '\0') {
            my_putstr(entry->d_name);
            my_putchar('\t');
        }
    }
}

int my_ls_flag_r(struct dirent *entry, DIR *dir)
{
    struct stat sb;
    while ((entry = readdir(dir)) != NULL) {
        stat(entry->d_name, &sb);
        if (entry->d_name[0] != '.' &&
        entry->d_name[0] != '\0' && S_ISDIR(sb.st_mode)) {
            display_path(entry->d_name);
            dir = opendir(entry->d_name);
            print_inside_dir(dir);
            my_putchar('\n');
            my_ls_flag_r(entry, dir);
        }
    }
    return 0;
}
