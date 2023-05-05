build:
	make object
	$(CC) main.c libtree.a -o tree

objectlist:
	$(MAKE) -C ../linkedlist object
	mv ../linkedlist/liblinkedlist.o .
objectstack:
	$(MAKE) -C ../stack object
	mv ../stack/libstack.o .
object:
	make objectstack
	make objectlist
	$(CC) -c tree.c liblinkedlist.o libstack.o -Wall -Wextra -o libtree.o  
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
