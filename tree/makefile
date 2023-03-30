build:

	make object
	gcc main.c tree.h libtree.a -o tree

objectlist:
	gcc -c ../linkedlist/linkedlist.c -Wall -Wextra -o liblinkedlist.o
objectstack:
	gcc -c ../stack/stack.c -Wall -Wextra -o libstack.o
object:
	make objectstack
	make objectlist
	gcc -c tree.c liblinkedlist.a libstack.a -Wall -Wextra -o libtree.o  
	ar ruv libtree.a libtree.o libstack.o liblinkedlist.o

clean:
	-rm *.a
	-rm *.o

run: 
	make build
	./tree
	
valgrind:
	make build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./tree
