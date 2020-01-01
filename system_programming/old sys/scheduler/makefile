CC=gcc -ansi -pedantic-errors -Wall -Wextra -g

TARGET=test.out

DLL=/home/codezila/git/ds/doublylinkedlist/
SORTLL=/home/codezila/git/ds/sortedlinkedlist/
PQ=/home/codezila/git/ds/priorityqueue/
UID=/home/codezila/git/system_programming/uid/
HEADER_DS=/home/codezila/git/ds/include
HEADER_SP=/home/codezila/git/system_programming/include

REQ_SRC =\
$(DLL)doubly_linked_list.c\
$(SORTLL)sorted_linked_list.c\
$(PQ)priority_queue.c\
$(UID)uid.c

compile:
	$(CC) task.c scheduler.c test_file.c $(REQ_SRC) -I$(HEADER_DS) -I$(HEADER_SP) -o $(TARGET)	

clean:
	rm *.o test.out
