SRCS_CLIENT =	client_src/client.c

SRCS_SERVER =	server_src/server.c

SRCS_COMMON =	common_src/stdout.c

OBJS_CLIENT	=	${SRCS_CLIENT:.c=.o}

OBJS_SERVER	=	${SRCS_SERVER:.c=.o}

OBJS_COMMON =	${SRCS_COMMON:.c=.o}

CLIENT		=	client

SERVER		=	server

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

%.o: %.c
			$(CC) $(CFLAGS) -I./includes $< -c -o ${<:.c=.o}

all:		${CLIENT} ${SERVER}

${CLIENT}:	${OBJS_CLIENT} ${OBJS_COMMON}
			${CC} ${CFLAGS} ${OBJS_CLIENT} ${OBJS_COMMON} -o ${CLIENT}

${SERVER}:	${OBJS_SERVER} ${OBJS_COMMON}
			${CC} ${CFLAGS} ${OBJS_SERVER} ${OBJS_COMMON} -o ${SERVER}

bonus:		all

clean:
			rm -f ${OBJS_CLIENT}
			rm -f ${OBJS_SERVER}
			rm -f ${OBJS_COMMON}

fclean:		clean
			rm -f ${CLIENT}
			rm -f ${SERVER}

re:			fclean all

.PHONY:		all bonus clean fclean re
