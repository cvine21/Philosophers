NAME		=	philo_bonus

HEADER_NAME	=	philo_bonus.h

HEADER_PATH	=	includes_bonus/

SRCS_PATH	= 	srcs_bonus/

SRCS_LIST	=	main.c		parser.c		initialize.c\
				print.c		utils.c			create_process.c\
				threads.c	simulation.c

HEADER		=	$(addprefix $(HEADER_PATH), $(HEADER_NAME))

SRCS		=	$(addprefix $(SRCS_PATH), $(SRCS_LIST))

OBJS		=	$(patsubst %.c, %.o, $(SRCS))

CC			=	gcc

INCLUDES	=	-I$(HEADER_PATH)

CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)

PTHREAD		=	-lpthread

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