CC:= gcc
CFLAGS:= -Wall -O2 -c
OBJ:= ballclock

.PHONY:clean memcheck

$(OBJ): main.o stack.o queue.o
	$(CC) -o $@ $^
main.o:main.c queue.h stack.h
	$(CC) -o $@ $< $(CFLAGS)
queue.o:queue.c queue.h
	$(CC) -o $@ $< $(CFLAGS)
stack.o:stack.c stack.h
	$(CC) -o $@ $< $(CFLAGS)

clean:
	-rm *.o $(OBJ)
memcheck:
	valgrind --tool=memcheck ./$(OBJ)
