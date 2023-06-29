build:
	make object
	$(CC) $(CFLAGS) main.c libunionfind.a -Wall -Wextra -o unionfind 
	
run:
	make build
	./unionfind
	make clean
	
object:
	$(CC) $(CFLAGS) -c unionfind.c -Wall -Wextra -o libunionfind.o
	ar rcs libunionfind.a libunionfind.o

clean:
	-rm libunionfind.a
	-rm libunionfind.o
	-rm libunionfind	
	-rm valgrind-*
valgrind:
	make build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./unionfind
