mmapcopy: mmapcopy.o csapp.o
	gcc -o mmapcopy mmapcopy.o csapp.o -lpthread
mmapcopy.o: mmapcopy.c csapp.h
	gcc -c mmapcopy.c
csapp.o: csapp.c csapp.h
	gcc -c csapp.c
clean:
	rm -f mmapcopy *.o
