# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gborne <gborne@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 02:04:31 by gborne            #+#    #+#              #
#    Updated: 2022/02/04 08:01:10 by gborne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER		=	server
CLIENT		=	client
CC			=	gcc
SRCS		=	utils.c
LIBFT		=	libft/libft.a
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

%o:			%.c
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(SERVER) $(CLIENT)

$(CLIENT):	client.o
			make -C libft
			$(CC) $(CFLAGS) $(LIBFT) client.o -o $@

$(SERVER):	server.o
			make -C libft
			$(CC) $(CFLAGS) $(LIBFT) server.o -o $@

clean:
			$(RM) server.o client.o

fclean:		clean
			$(RM) $(SERVER) $(CLIENT)
			make fclean -C libft/

re:			fclean all

git:
	@git add *
	@git commit -m "$m"
	@git push
	@echo "Commit sent to github"
# Para chamar: make git m="meu commit"

.PHONY:		all clean fclean re
