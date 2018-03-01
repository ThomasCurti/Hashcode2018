# Makefile

CC=gcc -fsanitize=address
CPPFLAGS= -MMD -D_XOPEN_SOURCE=500
CFLAGS= -Wall -Wextra -std=c99 -g -O3
LDFLAGS=
LDLIBS=


SRC= file.c hash.c
OBJ= ${SRC:.c=.o}
DEP= ${SRC:.c=.d}

all: hash

-include ${DEP}

hash: ${OBJ}
	${CC} ${CFLAGS} -o hash ${OBJ}

clean:
	rm -f ${OBJ} ${DEP} hash

# END
