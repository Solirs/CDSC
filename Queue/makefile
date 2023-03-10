build:
	make object
	make objectlist
	gcc main.c queue.h ../doublylinkedlist/doublylinkedlist.h libqueue.a libdoublylinkedlist.a  -o queue 

objectlist:
	gcc -c ../doublylinkedlist/doublylinkedlist.c -Wall -Wextra -o libdoublylinkedlist.o
	ar rcs libdoublylinkedlist.a libdoublylinkedlist.o

object:
	gcc -c queue.c libdoublylinkedlist.a -Wall -Wextra -o libqueue.o  
	ar rcs libqueue.a libqueue.o

clean:
	-rm *.a
	-rm *.o

run: 
	make build
	./queue