CC=gcc
CFLAGS=-I.
LIBFLAG = -L. -Wl,-rpath,. -lresistance -lcomponent -lpower
DEPS=
OBJS=main.o
SOBJS=libresistance.so libcomponent.so libpower.so
DESTDIR=/usr/local
EXEC_FILE=electrotest

all: $(EXEC_FILE)

main.o: main.c lib

$(EXEC_FILE): $(OBJS)
	$(CC) $^ -o $@ $(CFLAGS) $(LIBFLAG)

$(OBJS):
	$(CC) -c -o $@ $< $(CFLAGS)

lib: $(SOBJS)

%.so: %.c
	$(CC) $< $(CFLAGS) -shared -fPIC -o $@

.PHONY: clean
clean:
	rm -f $(EXEC_FILE) *.o *.so

install: $(EXEC_FILE)
	install -m 0755 $(EXEC_FILE) $(DESTDIR)/bin

uninstall:
	rm -f $(DESTDIR)/bin/$(EXEC_FILE)
