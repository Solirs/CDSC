build:
	make object
	$(CC) main.c libbtree.a -o binary_tree

objectlist:
	$(MAKE) -C ../linkedlist object
	mv ../linkedlist/liblinkedlist.o .
objectstack:
	$(MAKE) -C ../stack object
	mv ../stack/libstack.o .
object:
	make objectstack
	make objectlist
	$(CC) -c binary_tree.c -Wall -Wextra -o libbtree.o 
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
