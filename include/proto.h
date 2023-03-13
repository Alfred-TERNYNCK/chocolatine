/*
** EPITECH PROJECT, 2022
** proto
** File description:
** final stumper C pool
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#ifndef PROTO_H_
    #define PROTO_H_

int my_ls_flag_l(struct dirent *entry, DIR *dir, char *path);
int my_ls_flag_a(struct dirent *entry, DIR *dir);
int my_ls_flag_d(struct dirent *entry, DIR *dir);
int my_ls_flag_r(struct dirent *entry, DIR *dir);
int my_ls_flag_t(struct dirent *entry, DIR *dir);
void flag_l_color(struct dirent *entry, DIR *dir, struct stat sb);
int selector(int ac, char **av, struct dirent *entry, DIR *dir);
int my_ls(struct dirent *entry, DIR *dir);
int my_ls_flag_r_little(struct dirent *entry, DIR *dir);
void total_blocks(void);
char *my_putstr_sp(char *str);
char *gett_path(char *path, struct dirent *entry);

#endif
