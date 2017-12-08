CC=gcc

CFLAGS1 = -Wall -g -c
CFLAGS2 = -g
CFLAGS_SHARED = -Wall -shared -g -c

# Link the two object files together.
all: 
	make libcomponent
	gcc -o main.exe main.o
	gcc -L/libresistance -Wall -o electrotest main.c -lfoo

	

all: main.o libcomponent.o libpower.o libresistance.o 
	${CC} ${CFLAGS2} -o electrotest main.o libcomponent.o libpower.o libresistance.o -lm

#Compile source files to object files.
main.o: main.c
	${CC} ${CFLAGS1} -o main.o main.c

libcomponent.o: libcomponent.c
	${CC} ${CFLAGS1} -o libcomponent.o libcomponent.c

libpower.o: libpower.c
	${CC} ${CFLAGS1} -o libpower.o libpower.c

libresistance.o: libresistance.c
	${CC} ${CFLAGS1} -o libresistance.o libresistance.c

lib: libcomponent.o libpower.o libresistance.o
	mkdir -p ./lib
	gcc -shared -o ./lib/libcomponent.so libcomponent.o
	gcc -shared -o ./lib/libpower.so libpower.o
	gcc -shared -o ./lib/libresistance.so libresistance.o

clean:
	rm -rf ./lib
	rm -f libresistance *.o
	rm -f *.so
install:
	make all
	mv electrotest /usr/local/bin/electrotest

	#put project in : usr/local/bin
uninstall:
	make clean
	rm /usr/local/bin/electrotest
