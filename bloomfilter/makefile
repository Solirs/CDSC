build:
	make object
	$(CC) $(CFLAGS) main.c libbloomfilter.a -Wall -Wextra -o bloomfilter
	
run:
	make build
	./bloomfilter
	make clean
	

objectbitarray:
	$(MAKE) -C ../bitarray object
	mv ../bitarray/libbitarray.o .


object:
	make objectbitarray
	$(CC) $(CFLAGS) -c bloomfilter.c -Wall -Wextra -lm -o libbloomfilter.o
	ar rcs libbloomfilter.a libbloomfilter.o libbitarray.o

clean:
	-rm libbloomfilter.a
	-rm libbloomfilter.o
	-rm	bloomfilter
	-rm valgrind-*
valgrind:
	make build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./bloomfilter
