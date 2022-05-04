# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gborne <gborne@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 02:04:31 by gborne            #+#    #+#              #
#    Updated: 2022/04/28 18:29:33 by gborne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER		=	server
CLIENT		=	client
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

%o:			%.c
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(SERVER) $(CLIENT)

$(CLIENT):	client.o
			$(CC) $(CFLAGS) client.o -o $@

$(SERVER):	server.o
			$(CC) $(CFLAGS) server.o -o $@

clean:
			$(RM) server.o client.o

fclean:		clean
			$(RM) $(SERVER) $(CLIENT)

re:			fclean all

# Command: make git m="new commit"
git:
	@git add *
	@git commit -m "$m"
	@git push
	@echo "Commit sent to github"

.PHONY:		all clean fclean re
