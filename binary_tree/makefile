build:
	make object
	gcc main.c libbtree.a -o binary_tree

objectlist:
	gcc -c ../linkedlist/linkedlist.c -Wall -Wextra -o liblinkedlist.o
	ar rcs liblinkedlist.a liblinkedlist.o
objectstack:
	make objectlist
	gcc -c ../stack/stack.c -Wall -Wextra -o libstack.o
object:
	make objectstack
	gcc -c binary_tree.c -Wall -Wextra -o libbtree.o 
	ar ruv libbtree.a libbtree.o libstack.o liblinkedlist.o

clean:
	-rm *.a
	-rm *.o
	-rm ./binary_tree
	-rm valgrind*

run: 
	make build
	./binary_tree

	
valgrind:
	make build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./binary_tree
