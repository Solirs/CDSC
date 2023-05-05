build:
	make object
	$(CC) main.c libgraph.a -o graph $(CFLAGS)

run:
	make build
	./graph
	make clean

object:
	$(CC) -c graph.c -o libgraph.o $(CFLAGS) 
	ar rcs libgraph.a libgraph.o

clean:
	-rm *.a
	-rm *.o
	rm graph
valgrind:
	make build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./graph

