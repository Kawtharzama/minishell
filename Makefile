# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kabu-zee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/28 15:46:34 by kabu-zee          #+#    #+#              #
#    Updated: 2025/02/28 15:46:37 by kabu-zee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/minishell.c #src.c

OBJS = $(SRCS:srcs/%.c=objs/%.o) #ending with .c replace it with .o just as string 

CC = cc

CFLAGS= -Wall -Wextra -Werror -g 

INCLUDES= -I./includes -I./libft

LIB_PATH = ./libft

#LIB = ./libft/libft.a

LINK = -L$(LIB_PATH) -lft 

NAME = minishell

all: LIB $(NAME)

LIB:
	make -C $(LIB_PATH)

$(NAME): $(OBJS)
 	$(CC) $(OBJS) $(LINK) -o $@


objs/%.o : srcs/%.c  minishell.h     #implicit rule , trace the header file    $@   $< $^ $1 
	mkdir -p objs
	$(CC) $(CFLAGS) $(INCLUDES) -c  $< -o $@

clean:
	rm -rf $(OBJS)
	rm -rf objs 
	make clean -C $(LIB_PATH) 

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_acPATH)	

re: fclean all

.PHONY: all clean fclean re LIB


