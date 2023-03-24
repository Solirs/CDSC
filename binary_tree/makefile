build:
	make object
	gcc main.c libbtree.a -o binary_tree

object:
	gcc -c binary_tree.c -Wall -Wextra -o libbtree.o 
	ar rcs libbtree.a libbtree.o

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
