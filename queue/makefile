build:
	make objectlist
	make object
	gcc main.c queue.h ../linkedlist/linkedlist.h libqueue.a liblinkedlist.a  -o queue 

objectlist:
	gcc -c ../linkedlist/linkedlist.c -Wall -Wextra -o liblinkedlist.o

object:
	gcc -c queue.c liblinkedlist.a -Wall -Wextra -o libqueue.o  
	ar ruv libqueue.a libqueue.o liblinkedlist.o

clean:
	-rm *.a
	-rm *.o

run: 
	make build
	./queue
