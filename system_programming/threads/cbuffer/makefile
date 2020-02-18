#make file - this is a comment section

CC=gcc -ansi -pedantic-errors -Wall -Wextra -g -I./../../include #compiler
TARGET=cbuffer_thread #target file name

all:  
	$(CC) cbuffer_thread.c cbuffer_thread_test.c -o $(TARGET) -pthread

clean:
	rm $(TARGET)

