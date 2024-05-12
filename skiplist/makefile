build:
	make object
	$(CC) $(CFLAGS) main.c libskiplist.a -o skiplist

objectlist:
	$(MAKE) -C ../doublylinkedlist object
	mv ../doublylinkedlist/libdoublylinkedlist.o .

object:
	make objectlist
	$(CC) $(CFLAGS) -c skiplist.c -Wall -Wextra -o libskiplist.o  
	ar ruv libskiplist.a libskiplist.o libdoublylinkedlist.o

clean:
	-rm *.a
	-rm *.o

run: 
	make build
	./skiplist
	
valgrind:
	make build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./skiplist
