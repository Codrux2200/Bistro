##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## desc
##

SRC     =       ./lib/my/my_putstr.c	\
                ./lib/my/my_strcpy.c	\
                ./lib/my/my_getnbr.c	\
                ./lib/my/my_strlen.c  \
                ./lib/my/my_rev_str.c	\
		 		./lib/my/add.c	\
				./infin_add.c	\

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

NAME2	= 	./lib/my/my.h

all:	compil_lib compil_my

compil_lib:	$(OBJ)
		gcc -o calc *.c ./lib/my/*.c
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ..
		chmod +x $(NAME)

compil_my:
		cp $(NAME2) ./include

clean:
		rm -f $(OBJ)

fclean:	clean
	rm calc
	rm ./include/my.h
	rm libmy.a

re : fclean all
