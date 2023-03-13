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

char *my_putstr_sp(char *str)
{
    int i = 4;

    while (str[i - 3] != ':' && str[i] != '\0') {
        if (str[i] == '\n') {
            i++;
        } else {
            my_putchar(str[i]);
        }
        i++;
    }
    return str;
}
