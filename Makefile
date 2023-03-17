CC=gcc
CFLAGS=-I.
DEPS = img.h harmonograph.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

harmonograph: main.o img.o harmonograph.o
	$(CC) -o harmonograph main.o img.o harmonograph.o
