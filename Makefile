CC=gcc
CFLAGS=-Wall -std=c99
LDFLAGS=-L/usr/local/lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
INFLAGS=-I/usr/local/include
main: main.c
		$(CC) -o main main.c $(CFLAGS) $(INFLAGS) $(LDFLAGS) -DPLATFORM_DESKTOP

.PHONY: clean
clean:
	rm -rf *.o main
