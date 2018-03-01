# Makefile
 
CC = gcc -fsanitize=address
CPPFLAGS = -MMD
CFLAGS = -Wall -Wextra -std=c99 -O0 -g
LDFLAGS =
LDLIBS =
 
OBJ = matrix.o main.o ride.o
DEP = ${OBJ:.o=.d}
 
all: main
 
main: ${OBJ}
 
.PHONY: clean
 
clean:
	${RM} ${OBJ} ${DEP} main
 
-include ${DEP}
 
# END