compile: string.o
	gcc string.c

run:
	./a.out

string.o: string.c string.h
	gcc -c string.c

clean:
	rm *.o a.out
