SHELL:=/bin/sh -O extglob
format:
	indent -kr -brf */*.c
	rm */*~

# Command to build every CDSC data structure into a single object
all: 


	for x in $(shell ls */!(main*).c); do \
		$(CC) $(CFLAGS) -c $$x -Wall -Wextra -o $$x.o; \
		mv $$x.o .; \
	done \

	ar rcs libcdsc.a *.c.o; \
	rm *.c.o; \
