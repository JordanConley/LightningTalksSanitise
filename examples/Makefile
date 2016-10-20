
CFLAGS=-std=gnu99 -O0 -Wall -Wextra

all: bo race1 race2 derefnull customhandler

bo: bo.c
	cc bo.c $(CFLAGS) -fsanitize=address -o bo

derefnull: derefnull.c
	cc derefnull.c $(CFLAGS) -fsanitize=address -o derefnull

race1: race1.c
	cc race1.c $(CFLAGS) -fsanitize=thread -pthread -o race1

race2: race2.c
	cc race2.c $(CFLAGS) -fsanitize=thread -pthread -o race2

customhandler: customhandler.c
	cc customhandler.c $(CFLAGS) -fsanitize=undefined -fsanitize-undefined-trap-on-error -pthread -o customhandler

.PHONY: clean
clean:
	rm -f bo race1 race2 derefnull customhandler

