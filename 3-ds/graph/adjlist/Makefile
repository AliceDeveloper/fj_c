CC:= gcc
CFLAGS:= -Wall -O2 -c
OBJS:= adjlist.o queue.o

main: $(OBJS)
	$(CC) -o $@ $^
adjlist.o:adjlist.c
	$(CC) $(CFLAGS) -o $@ $^
queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean

clean:
	-rm $(OBJS) main

