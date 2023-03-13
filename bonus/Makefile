##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Compiler
##

NAME	= my_ls

CC		= gcc

RM		= rm -f

SRC		= src/main.c \
			src/flag.c \
			src/selector.c \
			src/utils.c \
			src/flag_l.c \
            src/color.c

OBJ		= $(SRC:.c=.o)

LIBFLAG	= -L lib/my/ -lmy

CFLAGS = -I include/

all: $(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my
	$(CC) $(SRC) -o $(NAME) $(LIBFLAG) $(CFLAGS)


clean:
	rm -rf $(OBJ)
	$(MAKE) clean -C lib/my clean
	$(RM) *.gcno *.gcda

fclean:		clean
	rm -rf $(NAME)
	$(MAKE) fclean -C lib/my fclean

re:			fclean all

test_run : $(MAKE) -C ../tests

.PHONY:		all clean fclean re
