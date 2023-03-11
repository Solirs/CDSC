build:
	make objectlist
	make object
	gcc main.c stack.h ../doublylinkedlist/doublylinkedlist.h libstack.a libdoublylinkedlist.a  -o stack

objectlist:
	gcc -c ../doublylinkedlist/doublylinkedlist.c -Wall -Wextra -o libdoublylinkedlist.o
	ar rcs libdoublylinkedlist.a libdoublylinkedlist.o

object:
	gcc -c stack.c libdoublylinkedlist.a -Wall -Wextra -o libstack.o  
	ar rcs libstack.a libstack.o

clean:
	-rm *.a
	-rm *.o

run: 
	make build
	./stack