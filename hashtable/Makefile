CFLAGS = -Wall -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast

build:
	make object
	gcc main.c libhashtable.a -o hashtable $(CFLAGS)

run:
	make build
	./hashtable
	make clean

object:
	gcc -c hashtable.c -o libhashtable.o $(CFLAGS) 
	ar rcs libhashtable.a libhashtable.o

clean:
	-rm *.a
	-rm *.o