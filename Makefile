CC=gcc

CFLAGS1 = -Wall -g -c
CFLAGS2 = -g

# Link the two object files together.
all: libresistance.o 
	${CC} ${CFLAGS2} -o libresistance libresistance.o

#Compile source files to object files.

clean:
	rm -f libresistance *.o
install:
	make all
	mv libresistance /usr/local/bin/libresistance
uninstall:
	make clean
	rm /usr/local/bin/libresistance
