# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 10:07:21 by mtrembla          #+#    #+#              #
#    Updated: 2021/11/22 17:32:36 by mtrembla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h

SRCS = ft_printf.c \
	   printutil.c \

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
AR = ar rc
RM = rm -rf
OBJS = $(SRCS:.c=.o)

SDIR = src
ODIR = objs

SFIX = $(addprefix $(SDIR)/, $(SRCS))
OFIX = $(addprefix $(ODIR)/, $(OBJS))

$(NAME): $(ODIR) $(OFIX)
		$(AR) $(NAME) $(OFIX)

$(ODIR): 
		mkdir -p $(ODIR)

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) $< -o $@
		

all: $(NAME)

clean:
		$(RM) $(OFIX) $(ODIR)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
