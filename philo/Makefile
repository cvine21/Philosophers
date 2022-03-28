NAME		=	philo

HEADER_PATH	=	includes/

LIBFT		=	libft/

SRCS_PATH	= 	srcs/

SRCS_LIST	=	main.c		parse.c				init.c\
				time.c		create_philos.c		action.c\

HEADER		=	$(addprefix $(HEADER_PATH), philo.h)

SRCS		=	$(addprefix $(SRCS_PATH), $(SRCS_LIST))

OBJS		=	$(patsubst %.c, %.o, $(SRCS))

CC			=	gcc

INCLUDES	=	-I$(HEADER_PATH) -I$(LIBFT)$(HEADER_PATH)

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