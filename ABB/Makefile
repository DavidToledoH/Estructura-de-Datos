run: a.out
	./a.out
a.out: main.o ABB.o
	gcc main.o ABB.o
main.o: main.c
		gcc main.c -c
contigua.o: ABB.c
	gcc ABB.c -c
clear:
	rm -f *.o a.out
