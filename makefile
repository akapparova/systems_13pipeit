all: pipeit.c
	gcc pipeit.c
run: all
	./a.out
clean:
	rm a.out
	rm *~
