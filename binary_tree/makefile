build:
	make object
	gcc main.c binary_tree.h libbtree.a -o binary_tree

objectstack:
	gcc -c ../stack/stack.c -Wall -Wextra -o libstack.o
object:
	make objectstack
	gcc -c binary_tree.c libstack.a -Wall -Wextra -o libbtree.o 
	ar ruv libbtree.a libbtree.o libstack.o

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
