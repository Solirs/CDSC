build:
	make object
	gcc main.c libstack.a  -o stack


object:
	gcc -c stack.c  -Wall -Wextra -o libstack.o  
	ar rcs libstack.a libstack.o

clean:
	-rm *.a
	-rm *.o

run: 
	make build
	./stack