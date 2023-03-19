build:
	make objectlist
	make object
	gcc main.c deque.h ../linkedlist/linkedlist.h libdeque.a liblinkedlist.a  -o deque

objectlist:
	gcc -c ../linkedlist/linkedlist.c -Wall -Wextra -o liblinkedlist.o
	ar rcs liblinkedlist.a liblinkedlist.o

object:
	gcc -c deque.c liblinkedlist.a -Wall -Wextra -o libdeque.o  
	ar rcs libdeque.a libdeque.o

clean:
	-rm *.a
	-rm *.o

run: 
	make build
	./deque
valgrind:
	make build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./deque
