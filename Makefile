SRC_FILES = convex_hull.c area.c stack.c predicates.c include/gfx.c
# I want to little explain my strange decision to use -Wno-unused-variable
# the variables ba and ca are effectivle unused, but maybe i will use them into a
# far future instead for P and n: they are both defined and used and gcc for some reasons
# say that's is not (or at least i think that it's not), so my pc my rules...
CC_FLAGS = -std=c99 -Wall -g -Wextra -lX11 -Wno-unused-variable
CC = gcc

all:
	${CC} ${SRC_FILES} ${CC_FLAGS} -o convex_hull.o

clean:
	rm -rf *~ *.o *.out
