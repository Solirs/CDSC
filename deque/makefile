build:
	make objectlist
	make object
	gcc main.c deque.h libdeque.a -o deque

objectlist:
	gcc -c ../linkedlist/linkedlist.c -Wall -Wextra -o liblinkedlist.o

object:
	gcc -c deque.c -Wall -Wextra -o libdeque.o  
	ar ruv libdeque.a libdeque.o liblinkedlist.o

clean:
	-rm *.a
	-rm *.o

run: 
	make build
	./deque
valgrind:
	make build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./deque
