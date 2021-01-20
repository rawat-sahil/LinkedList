CC=gcc
FLAGS=-g
target=main
all:
	$(CC) $(FLAGS) main.c helper.h helper.c -o $(target)

clean:
	rm $(target)
