CC=gcc
CFLAGS = -std=c99 -Wall

filecopy: src/filecopy.c
	$(CC) $(CFLAGS) src/filecopy.c -o build/filecopy

treecopy: src/treecopy.c
	$(CC) $(CFLAGS) src/treecopy.c -o build/treecopy