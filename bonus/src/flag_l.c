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

const void flag_l_help(struct dirent *entry, DIR *dir, struct stat sb)
{
    my_putstr(S_ISDIR(sb.st_mode) ? "d" : "-");
    my_putstr(sb.st_mode & S_IRUSR ? "r" : "-");
    my_putstr(sb.st_mode & S_IWUSR ? "w" : "-");
    my_putstr(sb.st_mode & S_IXUSR ? "x" : "-");
    my_putstr(sb.st_mode & S_IRGRP ? "r" : "-");
    my_putstr(sb.st_mode & S_IWGRP ? "w" : "-");
    my_putstr((sb.st_mode & S_IXGRP) ? ("x") : ("-"));
    my_putstr(sb.st_mode & S_IROTH ? "r" : "-");
    my_putstr(sb.st_mode & S_IWOTH ? "w" : "-");
    my_putstr((sb.st_mode & S_IXOTH) ? ("x") : ("-"));
    my_putchar('.');
    my_putchar(' ');
    my_put_nbr(sb.st_nlink);
    my_putchar(' ');
    my_putstr(getpwuid(sb.st_uid)->pw_name);
    my_putchar(' ');
    my_putstr(getgrgid(sb.st_gid)->gr_name);
    my_putchar(' ');
}

void total_blocks(void)
{
    DIR *dir = opendir(".");
    struct dirent *entry = readdir(dir);
    int total = 0;
    struct stat sb; stat(entry->d_name, &sb);
    while ((entry = readdir(dir)) != NULL) {
        stat(entry->d_name, &sb);
        total += sb.st_blocks;
    }
    my_putstr("total ");
    my_put_nbr(total / 2);
    my_putchar('\n');
}

int my_ls_flag_l(struct dirent *entry, DIR *dir)
{
    struct stat sb; stat(entry->d_name, &sb);
    total_blocks();
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            stat(entry->d_name, &sb);
            flag_l_help(entry, dir, sb);
            my_put_nbr(sb.st_size);
            my_putchar(' ');
            my_putstr_sp(ctime(&sb.st_mtime));
            my_putchar(' ');
            flag_l_color(entry, dir, sb);
            my_putchar('\n');
            stat(entry->d_name, &sb);
        }
    }
    return 0;
}
