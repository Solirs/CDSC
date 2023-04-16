build:
	make object
	gcc main.c stack.h ../linkedlist/linkedlist.h libstack.a  -o stack

objectlist:
	gcc -c ../linkedlist/linkedlist.c -Wall -Wextra -o liblinkedlist.o

object:
	make objectlist
	gcc -c stack.c -Wall -Wextra -o libstack.o  
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
