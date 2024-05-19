myname: hello.o in.o
	gcc -o myname hello.o in.o
in.o: in.c in.h
	gcc -o in.o in.c -c
hello.o: hello.c in.h
	gcc -o hello.o hello.c -c
run: myname

clean: 
	rm -r myname
