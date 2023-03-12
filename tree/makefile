build:
	make objectlist
	make object
	gcc main.c tree.h ../linkedlist/linkedlist.h libtree.a liblinkedlist.a  -o tree

objectlist:
	gcc -c ../linkedlist/linkedlist.c -Wall -Wextra -o liblinkedlist.o
	ar rcs liblinkedlist.a liblinkedlist.o

object:
	gcc -c tree.c liblinkedlist.a -Wall -Wextra -o libtree.o  
	ar rcs libtree.a libtree.o

clean:
	-rm *.a
	-rm *.o

run: 
	make build
	./tree