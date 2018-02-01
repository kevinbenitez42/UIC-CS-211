ResturantQueue: source1.o source2.o llist.o
	gcc -o ResturantQueue source1.o source2.o llist.o

source1.o: source1.c llist.h
	gcc -c source1.c

source2.o: source2.c llist.h
	gcc -c source2.c

llist.o: llist.c llist.h
	gcc -c llist.c

clean:
	rm source1.o source2.o llist.o ResturantQueue
