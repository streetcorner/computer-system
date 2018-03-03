main: main.o myMalloc.o
	gcc -o main main.o myMalloc.o
main.o: main.c myMalloc.h
	gcc -c main.c
mymalloc.o: myMalloc.c myMalloc.h
	gcc -c myMalloc.c

clean:
	rm -f main *.o
