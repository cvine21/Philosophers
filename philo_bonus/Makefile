NAME		=	philo_bonus

HEADER_NAME =	philo_bonus.h

HEADER_PATH	=	includes_bonus/

LIBFT		=	../libft/

LIB_HEADER	=	../libft/includes/

SRCS_PATH	= 	srcs_bonus/

SRCS_LIST	=	main.c		parser.c	initialize.c\
				print.c		utils.c	create_process.c\
				threads.c	simulation.c

HEADER		=	$(addprefix $(HEADER_PATH), $(HEADER_NAME))

SRCS		=	$(addprefix $(SRCS_PATH), $(SRCS_LIST))

OBJS		=	$(patsubst %.c, %.o, $(SRCS))

CC			=	gcc

INCLUDES	=	-I$(HEADER_PATH) -I$(LIB_HEADER)

CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)

LIB_FLAGS 	=	-L$(LIBFT) -lft -lpthread

.PHONY		:	all clean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(LIB_FLAGS) $(OBJS) -o $@

%.o			:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean		:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean		:	clean
	$(MAKE) fclean -C $(LIBFT)
	$(RM) $(NAME)

re			:	fclean all