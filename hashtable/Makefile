CFLAGS = -Wall -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast

build:
	make object
	$(CC) main.c libhashtable.a -o hashtable $(CFLAGS)

run:
	make build
	./hashtable
	make clean

object:
	$(CC) -c hashtable.c -o libhashtable.o $(CFLAGS) 
	ar rcs libhashtable.a libhashtable.o

clean:
	-rm *.a
	-rm *.o
	rm hashtable
valgrind:
	make build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./hashtable
