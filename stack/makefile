build:
	make object
	$(CC) main.c libstack.a  -o stack

objectlist:
	$(MAKE) -C ../linkedlist object
	mv ../linkedlist/liblinkedlist.o .

object:
	make objectlist
	$(CC) -c stack.c -Wall -Wextra -o libstack.o  
	ar rcs libstack.a libstack.o liblinkedlist.o

clean:
	-rm *.a
	-rm *.o

run: 
	make build
	./stack
valgrind:
	make build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./stack
