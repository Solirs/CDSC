build:
	make object
	$(CC) $(CFLAGS) main.c libbitarray.a -Wall -Wextra -o bitarray
	
run:
	make build
	./bitarray
	make clean
	
object:
	$(CC) $(CFLAGS) -c bitarray.c -Wall -Wextra -o libbitarray.o
	ar rcs libbitarray.a libbitarray.o

clean:
	-rm libbitarray.a
	-rm libbitarray.o
	-rm	bitarray
	-rm valgrind-*
valgrind:
	make build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./bitarray
