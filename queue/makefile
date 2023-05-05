build:
	make object
	$(CC) $(CFLAGS) main.c libqueue.a -o queue 

objectlist:
	$(MAKE) -C ../doublylinkedlist object
	mv ../doublylinkedlist/libdoublylinkedlist.o .

object:
	make objectlist
	$(CC) -c queue.c -Wall -Wextra -o libqueue.o  
	ar ruv libqueue.a libqueue.o libdoublylinkedlist.o

clean:
	-rm *.a
	-rm *.o

run: 
	make build
	./queue
valgrind:
	make build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./queue
