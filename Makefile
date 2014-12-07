CFLAGS=-Wall -g -std=c99 -o
CC=gcc

dynstringsTest: Tests/main.c src/dynstrings.c
	$(CC) $(CFLAGS) $@ $^