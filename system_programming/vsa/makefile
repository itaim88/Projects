#make file - this is a comment section
#gcc -std=c99 -pedantic-errors -Wall -Wextra -DNDEBUG -O3
#gcc -ansi -pedantic-errors -Wall -Wextra -g

CC=gcc -ansi -pedantic-errors -Wall -Wextra -g -I./../include #compiler
TARGET=vsa #target file name

all:  
	$(CC) vsa.c vsa_test.c -o $(TARGET)

clean:
	rm $(TARGET)

