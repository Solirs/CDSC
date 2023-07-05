build:
	make object
	$(CC) $(CFLAGS) main.c librope.a -Wall -Wextra -o rope

run:
	make build
	./rope
	make clean

object:
	$(CC) $(CFLAGS) -c rope.c -Wall -Wextra -o librope.o
	ar rcs librope.a librope.o

clean:
	-rm librope.a
	-rm librope.o
	-rm librope
	-rm valgrind-*
valgrind:
	make build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./rope
