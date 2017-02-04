CC=gcc
CFLAGS=-I. -std=c99 -Wall -Wextra -Wpedantic
LIBFLAG = -L. -Wl,-rpath,. -lresistance

all: testlib.c libresistance.so
	$(CC) $(CFLAGS) -o testlib testlib.c $(LIBFLAG)

%.so: %.c
	$(CC) $< $(CFLAGS) -shared -fPIC -o $@

.PHONY: clean
clean:
	rm -f *.o *.so testlib

