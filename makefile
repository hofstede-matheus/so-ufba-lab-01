CC=gcc
CFLAGS = -std=c99 -Wall

define clean
    rm -f src/*.o
endef

filecopy: src/filecopy.c src/errors.o src/errors.h
	mkdir -p build
	$(CC) $(CFLAGS) src/filecopy.c src/errors.o -o build/filecopy

treecopy: src/treecopy.c src/errors.o src/errors.h
	mkdir -p build
	$(CC) $(CFLAGS) src/treecopy.c src/errors.o -o build/treecopy

clean:
	rm -f src/*.o
