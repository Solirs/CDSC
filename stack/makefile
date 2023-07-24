build:
	make object
	$(CC) $(CFLAGS) main.c libstack.a  -o stack

objectlist:
	$(MAKE) -C ../doublylinkedlist object
	mv ../doublylinkedlist/libdoublylinkedlist.o .

object:
	make objectlist
	$(CC) $(CFLAGS) -c stack.c -Wall -Wextra -o libstack.o  
	ar rcs libstack.a libstack.o libdoublylinkedlist.o

clean:
	-rm *.a
	-rm *.o

run: 
	make build
	./stack
valgrind:
	make build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./stack
