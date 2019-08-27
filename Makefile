#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2019/08/26 15:43:34 by blukasho          #+#    #+#             *#
#*   Updated: 2019/08/27 22:14:10 by blukasho         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

SRCS=rotword.c subword.c keyexpansion.c addroundkey.c subbytes.c shiftrows.c\
	 main.c mixcolumns.c cipher.c init.c

SRCSDIR=srcs/

OBJ=$(addprefix $(OBJDIR), $(SRCS:.c=.o))

OBJDIR=obj/

INCLUDES=-I./includes/

NAME=cryptoaes256

LIBNAME=libaes256.a

MAIN=srcs/main.c

FLAGS= -g3

all: makeobjdir $(NAME)

makeobjdir: 
	mkdir -p $(OBJDIR)

$(NAME): $(LIBNAME)
	gcc $(FLAGS) $(INCLUDES) $(MAIN) $(LIBNAME) -o $(NAME)

$(LIBNAME): $(OBJ)
	ar -rv $(LIBNAME) $^
	ranlib $(LIBNAME)

$(OBJDIR)%.o: $(SRCSDIR)%.c
	gcc $(FLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(LIBNAME)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
