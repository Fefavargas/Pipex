# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fefa <fefa@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 21:22:26 by fefa              #+#    #+#              #
#    Updated: 2024/10/24 21:23:44 by fefa             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			pipex
CC =			cc
CFLAGS =		-Wall -Wextra -Werror -g
LIBFT =			libft/libft.a
HDRS :=			pipex.h
SRCS = 			pipex.c util.c

OBJS = 			$(SRCS:.c=.o)

RM = rm -rf

${NAME}:$(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

all: ${NAME}

clean:
	${RM} ${OBJS}
	make clean -C ./libft

fclean:	clean
		${RM} ${NAME}	

re: fclean all

$(OBJS): $(HDRS)