CFLAGS = -Wall -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast

build:
	make object
	gcc main.c libheap.a -o heap $(CFLAGS)

run:
	make build
	./heap

object:
	gcc -c heap.c -o libheap.o $(CFLAGS) 
	ar rcs libheap.a libheap.o

clean:
	rm *.a
	rm *.o
	rm heap
