CC:= gcc
CFLAGS:= -Wall -O2 -c
OBJ:= bitree

.PHONY:clean memcheck

$(OBJ): main.o queue.o stack.o linknode.o
	$(CC) -o $@ $^
main.o:main.c queue.h stack.h linknode.h
	$(CC) -o $@ $< $(CFLAGS)
queue.o:queue.c queue.h linknode.h
	$(CC) -o $@ $< $(CFLAGS)
stack.o:stack.c stack.h linknode.h
	$(CC) -o $@ $< $(CFLAGS)
linknode.o:linknode.c linknode.h linknode.h
	$(CC) -o $@ $< $(CFLAGS)

clean:
	-rm *.o $(OBJ)
memcheck:
	valgrind --tool=memcheck ./$(OBJ)
