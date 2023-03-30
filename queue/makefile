build:
	make objectlist
	make object
	gcc main.c queue.h libqueue.a -o queue 

objectlist:
	gcc -c ../linkedlist/linkedlist.c -Wall -Wextra -o liblinkedlist.o

object:
	gcc -c queue.c -Wall -Wextra -o libqueue.o  
	ar ruv libqueue.a libqueue.o liblinkedlist.o

clean:
	-rm *.a
	-rm *.o

run: 
	make build
	./queue
valgrind:
	make build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./queue
