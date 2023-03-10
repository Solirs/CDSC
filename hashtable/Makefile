build:
	make object
	gcc main.c libhashtable.a -o hashtable -Wall -Wno-pointer-to-int-cast

run:
	make build
	./hashtable
	make clean

object:
	gcc -c hashtable.c -o libhashtable.o -Wall -Wno-pointer-to-int-cast
	ar rcs libhashtable.a libhashtable.o

clean:
	-rm *.a
	-rm *.o