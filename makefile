CC=gcc
CFLAGS = -Wall -g

filecopy: src/filecopy.c
	$(CC) $(CFLAGS) src/filecopy.c -o build/filecopy

treecopy: src/treecopy.c
	$(CC) $(CFLAGS) src/treecopy.c -o build/treecopy