build:
	make object
	gcc main.c liblinkedlist.a -Wall -Wextra -o linkedlist
	
run:
	make build
	./linkedlist
	make clean
	
object:
	gcc -c linkedlist.c -Wall -Wextra -o liblinkedlist.o
	ar rcs liblinkedlist.a liblinkedlist.o

clean:
	-rm liblinkedlist.a
	-rm liblinkedlist.o
	-rm	linkedlist
	-rm valgrind-*
valgrind:
	make build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./linkedlist
