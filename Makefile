memoization: main.o money_converter.o
	clang main.o money_converter.o -o memoization

02-minheap.o: main.c
	clang -c main.c 

heap.o: money_converter.c
	clang -c money_converter.c

clean:
	rm *.o memoization