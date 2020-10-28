# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 20:40:04 by zdnaya            #+#    #+#              #
#    Updated: 2019/11/04 17:34:28 by zdnaya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

INC = libft.h
	
SRC = *.c
      #ft_atoi.c
	  #ft_bzero.c
	  #ft_calloc.c
	  #ft_isalnum.c
	  #ft_isalpha.c
	  #ft_isaplpha.c
	  #ft_isascci.c
	  #ft_isdigit.c
	  #ft_isprint.c
	  #ft_memccpy.c
	  #ft_memchr.c
	  #ft_memcmp.c
	  #ft_memcpy.c
	  #ft_memmove.c
	  #ft_memset.c
	  #ft_strlcat.c
	  #ft_strchr.c
	  #ft_strdup.c
	  #ft_strlen.c
	  #ft_strncmp.c
	  #ft_strnstr.c
	  #ft_strrchr.c
	  #ft_tolower.c
	  #ft_toupper.c
	  #ft_itoa.c
	  #ft_putendl.c
	  #ft_putnbr_fd.c
	  #ft_putstr_fd.c
	  #ft_split.c
	  #ft_strjoin.c
	  #ft_strmapi.c
	  #ft_strtrim.c
	  #ft_substr.c
      #ft_putchar_fd.c

SRC_B = ft_lstnew.c ft_lstadd_front.c  ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

all : $(NAME)

$(NAME) :	
		@gcc $(CFLAGS) -c $(SRC) -I $(INC)
		@ar rc $(NAME) $(OBJ)
	   	@ranlib $(NAME)
%.o: %.c
	gcc $(CFLAGS) -c $<

bonus : all $(OBJ_B)
		ar rc $(NAME) $(OBJ_B)
		renlib $(NAME)
clean :
		@rm -rf $(OBJ)

fclean : clean
		@rm -rf $(NAME)

re: fclean all
