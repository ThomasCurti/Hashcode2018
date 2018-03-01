# Makefile
 
CC = gcc -fsanitize=address
CPPFLAGS = -MMD
CFLAGS = -Wall -Wextra -std=c99 -O0 -g
LDFLAGS =
LDLIBS =
 
OBJ = matrix.o pizza.o
DEP = ${OBJ:.o=.d}
 
all: pizza
 
pizza: ${OBJ}
 
.PHONY: clean
 
clean:
	${RM} ${OBJ} ${DEP} pizza
 
-include ${DEP}
 
# END