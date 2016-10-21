musicLib.o:
	gcc -std=c99 list.c main.c playlist.c -o musicLib.o

run: musicLib.o
	./musicLib.o

clean:
	rm musicLib.o
	
clear:
	 echo "MAKEFILE-\nmusicLib.o:\n\tgcc -std=c99 list.c main.c playlist.c -o musicLib.o\n\nrun: musicLib.o\n\t./musicLib.o\n\nclean:\n\trm musicLib.o\n"