build:
	make object
	$(CC) $(CFLAGS) main.c libdoublylinkedlist.a -Wall -Wextra -o doublylinkedlist


run:
	make build
	./doublylinkedlist
	make clean

object:
	$(CC) $(CFLAGS) -c doublylinkedlist.c -Wall -Wextra -o libdoublylinkedlist.o
	ar rcs libdoublylinkedlist.a libdoublylinkedlist.o

clean:
	-rm libdoublylinkedlist.a
	-rm libdoublylinkedlist.o
	-rm doublylinkedlist
	-rm valgrind-*
valgrind:
	make build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./doublylinkedlist
