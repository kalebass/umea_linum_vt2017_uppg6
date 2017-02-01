CC=gcc
CFLAGS=-I.
DEPS=
OBJS=main.o
DESTDIR=/usr/local
EXEC_FILE=electrotest

all: $(EXEC_FILE)

main.o: main.c

$(EXEC_FILE): $(OBJS)
	$(CC) $^ -o $@ $(CFLAGS)

$(OBJS):
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(EXEC_FILE) *.o

install: $(EXEC_FILE)
	install -m 0755 $(EXEC_FILE) $(DESTDIR)/bin

uninstall:
	rm -f $(DESTDIR)/bin/$(EXEC_FILE)
