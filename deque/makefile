build:
	make object
	gcc main.c deque.h libdeque.a -o deque

objectlist:
	gcc -c ../doublylinkedlist/doublylinkedlist.c -Wall -Wextra -o libdoublylinkedlist.o

object:
	make objectlist
	gcc -c deque.c -Wall -Wextra -o libdeque.o  
	ar ruv libdeque.a libdeque.o libdoublylinkedlist.o

clean:
	-rm *.a
	-rm *.o

run: 
	make build
	./deque
valgrind:
	make build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./deque
