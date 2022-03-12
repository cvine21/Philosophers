NAME		=	philo

HEADER_PATH	=	includes/

SRCS_PATH	= 	srcs/

SRCS_LIST	=	multithreading_in_c.c

HEADER		=	$(addprefix $(HEADER_PATH), philo.h)

SRCS		=	$(addprefix $(SRCS_PATH), $(SRCS_LIST))

OBJS		=	$(patsubst %.c, %.o, $(SRCS))

CC			=	gcc

INCLUDES	=	-I$(HEADER_PATH)

CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)

RM			=	rm -f

PTHREAD 	=	-lpthread

.PHONY		:	all clean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(PTHREAD) $(OBJS) -o $@

%.o			:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean		:
	$(RM) $(OBJS)

fclean		:	clean
	$(RM) $(NAME)

re			:	fclean all