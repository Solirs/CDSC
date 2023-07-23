build:
	make object
	$(CC) $(CFLAGS) main.c libbloomfilter.a -Wall -Wextra -o bloomfilter
	
run:
	make build
	./bloomfilter
	make clean
	
object:
	$(CC) $(CFLAGS) -c bloomfilter.c -Wall -Wextra -o libbloomfilter.o
	ar rcs libbloomfilter.a libbloomfilter.o

clean:
	-rm libbloomfilter.a
	-rm libbloomfilter.o
	-rm	bloomfilter
	-rm valgrind-*
valgrind:
	make build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./bloomfilter
