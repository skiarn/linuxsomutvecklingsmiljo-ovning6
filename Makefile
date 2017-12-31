CC=gcc

CFLAGS1 = -Wall -g -c
CFLAGS2 = -g -Wall
CFLAGS_SHARED = -Wall -shared -g -c
CFLAGS3 = -g -Wall -shared -fPIC 
C4 = -L./lib/
C5 = '-Wl,-rpath,$$ORIGIN/lib/'
libs = -lcomponent -lpower -lresistance -lm
	

all: main.o libcomponent.so libpower.so libresistance.so 
	make lib
	${CC} ${CFLAGS2} main.o ${C4} ${libs} ${C5} -o electrotest

#Compile source files to object files.
main.o: main.c
	${CC} ${CFLAGS1} -o main.o main.c

libcomponent.so: libcomponent.c libcomponent.h
	mkdir -p ./lib
	${CC} ${CFLAGS3} -o ./lib/libcomponent.so $^

libpower.so: libpower.c libpower.h
	mkdir -p ./lib
	${CC} ${CFLAGS3} -o ./lib/libpower.so $^

libresistance.so: libresistance.c libresistance.h
	mkdir -p ./lib
	${CC} ${CFLAGS3} -o ./lib/libresistance.so $^

lib: libcomponent.c libcomponent.h libpower.c libcomponent.h libresistance.c libresistance.h
	make libpower.so
	make libcomponent.so
	make libresistance.so

clean:
	rm -rf ./lib
	rm -f libresistance *.o
	rm -f *.so
install:
	make all
	mv electrotest /usr/local/bin/electrotest
	mv ./lib/ /usr/local/bin/
	@ldconfig  
uninstall:
	make clean
	rm /usr/local/bin/electrotest
	rm /usr/local/bin/lib/libcomponent.so
	rm /usr/local/bin/lib/libpower.so
	rm /usr/local/bin/lib/libresistance.so
