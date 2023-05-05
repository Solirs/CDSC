build:
	make object
	$(CC) main.c libdeque.a -o deque

objectlist:
	$(MAKE) -C ../linkedlist object
	mv ../linkedlist/liblinkedlist.o .

object:
	make objectlist
	$(CC) -c deque.c -Wall -Wextra -o libdeque.o  
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
